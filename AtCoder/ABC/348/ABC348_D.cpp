// 2024/04/06 21:10:00
// 2024/04/06 22:06:12 2WA
// 2024/04/06 22:18:16 AC.
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>
using namespace std;
int main(){
    int H, W;
    cin >> H >> W;
    vector<string> A(H);
    for (string &a : A) {
        cin >> a;
    }
    int N;
    cin >> N;
    int S_h = -1, S_w = -1;
    vector<int> R(N), C(N), E(N);
    vector<vector<int>> M(H, vector<int>(W, -1)); // M[i][j] は 座標(i,j)に置かれた薬の番号
    for (int i = 0; i < N; i++) {
        cin >> R[i] >> C[i] >> E[i];
        R[i]--; C[i]--;
        M[R[i]][C[i]] = i;
        if (A[R[i]][C[i]] == 'S') {
            S_h = R[i];
            S_w = C[i];
        }
        if (A[R[i]][C[i]] == '.') {
            A[R[i]][C[i]] = 'M';
        }
    }
    if (S_h == -1) {
        cout << "No" << endl;
        return 0;
    }

    pair<int, int> dir4[4] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    vector<set<int>> G(N + 1);
    for (int i = 0; i < N; i++) {
        int h = R[i], w = C[i], e = E[i];
        vector<vector<int>> reachable(H, vector<int>(W, -1)); // 0:未到達 1:到達可能 -1:到達不可能
        queue<pair<pair<int, int>, int>> que;
        que.push({{h, w}, e});
        while (!que.empty()) {
            pair<pair<int, int>, int> tgt = que.front(); que.pop();
            int next_e = tgt.second - 1;
            if (next_e < 0) {
                continue;
            }
            for (int j = 0; j < 4; j++) {
                int next_h = tgt.first.first + dir4[j].first;
                int next_w = tgt.first.second + dir4[j].second;
                if (0 <= next_h && next_h < H && 0 <= next_w && next_w < W) {
                    if (A[next_h][next_w] != '#' && reachable[next_h][next_w] < next_e) {
                        reachable[next_h][next_w] = next_e;
                        que.push({{next_h, next_w}, next_e});
                        if (A[next_h][next_w] == 'M') {
                            G[i].insert(M[next_h][next_w]);
                            // G[M[next_h][next_w]].insert(i); // これが違うのか。双方向じゃないわ。
                        }
                        if (A[next_h][next_w] == 'T') {
                            G[i].insert(N); // NがTってことでよいか。
                            // G[N].insert(i);
                        }
                    }
                }
            }
        }
    }
    stack<int> stk;
    vector<bool> done(N + 1, false);
    stk.push(M[S_h][S_w]);
    done[stk.top()] = true;
    while (!stk.empty()) {
        int tgt = stk.top(); stk.pop();
        for (int next : G[tgt]) {
            if (done[next]) {
                continue;
            }
            stk.push(next);
            done[next] = true;
        }
    }
    cout << (done[N] ? "Yes" : "No") << endl;
    return 0;
}
/*
グラフ、か？
入力例3をどうやって解くのか分からない(2024/04/06 21:15:43)
現在時点から手持ちのエネルギーで移動できる範囲内にTが有ればTrue
さもなくば、範囲内にある薬の位置から同じことをやる？
間に合うのか…？(2024/04/06 21:20:24)
各薬の位置とエネルギーの範囲で被るかどうかだよね…
イメージは分かるんだけど。(2024/04/06 21:22:21)
各薬について到達できる薬またはTのグラフを作ればよいか。

4 * 200 * 200 * 300
間に合わない気がするな。(2024/04/06 21:33:01)

54AC, 2WA だと…
これは難しいな。
実行時間は意外と大丈夫そう。(2024/04/06 22:06:41)
*/
/*
最終的に、「ある薬から他の薬またはTに移動できるか」というグラフに落とし込むことを考える。
各薬について、その座標からその薬のエネルギーで移動できる範囲をグリッドのBFS(幅優先探索)で求め、到達できる他の薬またはTに有向辺を張る。
出来上がったグラフについて、Sにある薬からDFS(深さ優先探索)等して、Tまで到達できるかを判定すれば良い。(Sに薬がない場合は到達不可)
*/
