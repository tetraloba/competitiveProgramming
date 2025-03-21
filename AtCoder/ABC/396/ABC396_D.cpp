// 2025/03/21 22:06:50
// 2025/03/21 22:48:57 AC.
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct path{
    int ep; // endpoint
    int s; // set
    long long x; // xor sum
};
int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, long long>>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        u--; v--;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    long long ans = INT64_MAX;
    /* BFS */
    queue<path> que;
    que.push({0, 1 << 0, 0});
    while (!que.empty()) {
        path tgt = que.front(); que.pop();
        if (tgt.ep == N - 1) {
            ans = min(ans, tgt.x);
            continue;
        }
        for (auto [next, weight] : G[tgt.ep]) {
            if (tgt.s >> next & 1) {
                // 通過済みの頂点
                continue;
            }
            que.push({next, tgt.s | 1 << next, tgt.x ^ weight});
        }
    }
    cout << ans << endl;
    return 0;
}
/*
N小さいし，やるだけでは？(2025/03/21 22:08:11)
パスは10!だと3,628,800しかない。(2025/03/21 22:11:15)
始点終点が決まっているから8!か。(2025/03/21 22:12:37)
あーうそ。全部通るとは限らないから普通にBFSか。(2025/03/21 22:26:59)

無向グラフじゃないか。問題ちゃんと読め(2025/03/21 22:45:59)
単純グラフ，ループなしじゃないか。問題ちゃんと読め(2025/03/21 22:46:08)
*/
