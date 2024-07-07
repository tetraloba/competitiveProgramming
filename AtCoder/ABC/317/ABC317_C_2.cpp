// 2024/07/07 08:55:30
// 2024/07/07 09:36:03 AC.
#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <tuple>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<set<pair<int, int>>> G(N); // v, weight
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].insert({b, c});
        G[b].insert({a, c});
    }
    int max_dist = 0;
    stack<tuple<int, int, int>> stk; // v, weight, route
    for (int i = 0; i < N; i++) {
        stk.push({i, 0, 1 << i});
        while (!stk.empty()) {
            auto [tgt_v, tgt_dist, route] = stk.top(); stk.pop();
            if (max_dist < tgt_dist) {
                max_dist = tgt_dist;
            }
            for (auto [next_v, next_weight] : G[tgt_v]) {
                if (route >> next_v & 1) {
                    continue;
                }
                stk.push({next_v, tgt_dist + next_weight, 1 << next_v | route});
            }
            route ^= (1 << tgt_v);
        }
    }
    cout << max_dist << endl;
    return 0;
}
/*
経路の中では重複を許さないが、探索上は重複を許す深さ優先探索(DFS)？(2024/07/07 09:02:16)
*/
/*
高速化に成功！(2024/07/07 09:36:36)
あー解説は再帰使っているな。
そういえば最近全く再帰書いていないわ。
それにしても、used[]はグローバル変数にしているから、結局共通化できるのか…？
*/
