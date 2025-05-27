// 2025/03/29 21:09:11
// 2025/03/29 21:18:10 AC.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<bool> done(N);
    vector<int> union_sizes;
    for (int i = 0; i < N; i++) {
        if (done[i]) {
            continue;
        }
        int union_size = 0;
        /* BFS */
        queue<int> que;
        que.push(i);
        done[i] = true;
        while (!que.empty()) {
            int tgt = que.front(); que.pop();
            union_size++;
            for (int next : G[tgt]) {
                if (done[next]) {
                    continue;
                }
                que.push(next);
                done[next] = true;
            }
        }
        union_sizes.push_back(union_size);
    }
    /* debug */
    // for (int i : union_sizes) {
    //     cerr << i << ' ';
    // }
    // cerr << endl;

    int rest = 0;
    for (int i : union_sizes) {
        rest += i - 1;
    }
    cout << M - rest << endl;
    return 0;
}
/*
union-findしたら計算できるだろうけど・・・(2025/03/29 21:10:42)
*/
