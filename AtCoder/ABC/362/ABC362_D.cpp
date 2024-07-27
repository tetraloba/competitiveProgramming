// 2024/07/27 13:02:09
// 2024/07/27 13:44:03 AC.
#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
using LL=long long;
int main(){
    /* input */
    int N, M;
    cin >> N >> M;
    vector<int> A(N); // weight of vertex
    for (int &a : A) {
        cin >> a;
    }
    vector<set<pair<int, int>>> G(N); // graph (weight, vertex)
    for (int i = 0; i < M; i++) {
        int u, v, b;
        cin >> u >> v >> b;
        u--; v--;
        G[u].insert({b, v});
        G[v].insert({b, u});
    }

    /* solve (Dijkstra's algorithm) */
    vector<LL> ans(N, -1);
    priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>>> pque; // descending order (weight, vertex)
    pque.push({A[0], 0});
    while (!pque.empty()) {
        auto tgt = pque.top(); pque.pop();
        if (ans[tgt.second] != -1) {
            continue; // already done
        }
        ans[tgt.second] = tgt.first;
        for (auto next : G[tgt.second]) {
            if (ans[next.second] != -1) {
                continue; // already done
            }
            pque.push({(LL)tgt.first + A[next.second] + next.first, next.second});
        }
    }

    /* output */
    for (int i = 1; i < N; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}
/*
1から各頂点への最短距離を求めていけばよいのよね。

1 2 3

0 1 1
0 2 6
1 2 2

{1, 0}
ans={{0,1}}
{1+2+1,1}, {1+3+6,2}
ans={{0,1}, {1,4}}
{10,2}, {4+3+2,2}
*/
/*
普通にダイクストラ法だったね。
自力で実装できて良かった。
ダイクストラで茶色Diffとは恐るべし。
*/
