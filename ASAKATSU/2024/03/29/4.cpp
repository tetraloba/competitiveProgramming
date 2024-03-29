// 2024/03/29 08:15:55
// 2024/03/29 08:45:42 TLE
// 2024/03/29 09:45:39 AC.
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
int main(){
    /* 入力 */
    int N, M;
    cin >> N >> M;
    vector<map<int, int>> G(N);
    for (int i = 0; i < M; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        a--; b--;
        G[a][b] = t;
        G[b][a] = t;
    }

    /* 各2点間の最短距離を求める */
    vector<vector<long long>> dist(N, vector<long long>(N, __INT64_MAX__)); // 2点間の最短距離
    for (int i = 0; i < N; i++) {
        dist[i][i] = 0; // 自身との距離は0
    }
    priority_queue<
        pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>
    > pque;
    for (int i = 0; i < N; i++) {
        pque.push({0, i});
        while (!pque.empty()) {
            int tgt = pque.top().second; pque.pop();
            for (auto [k, v] : G[tgt]) {
                int d = dist[i][tgt] + v;
                if (d < dist[i][k]) {
                    dist[i][k] = d;
                    pque.push({dist[i][k], k});
                }
            }
        }
    }

    // /* debug */
    // for (auto d : dist) {
    //     for (auto i : d) {
    //         cout << i << ' ';
    //     }
    //     cout << endl;
    // }

    /* 全地点への最短距離の最長距離が最も短い地点を選ぶ() */
    long long min = __INT64_MAX__;
    for (int i = 0; i < N; i++) {
        long long max = dist[i][0];
        for (int j = 1; j < N; j++) {
            if (max < dist[i][j]) {
                max = dist[i][j];
            }
        }
        if (max < min) {
            min = max;
        }
    }
    cout << min << endl;
    return 0;
}
/*
グラフにおける最長の最短経路・・・
ダイクストラ法(動的計画法)のイメージなのはわかるんだけどなあ。。。
各頂点からの最短距離を全探索って間に合うのか？計算方法わからないぞ・・・
っていうかダイクストラの実装方法も覚えていないか。考えよう…(2024/03/29 08:26:04)
*/
