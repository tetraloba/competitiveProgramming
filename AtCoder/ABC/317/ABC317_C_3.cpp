// 2024/07/07 09:56:25
// 2024/07/07 10:59:30 AC.
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
    stack<tuple<int, int, int>> stk; // v, weight, depth
    stack<int> route; // 現在の経路
    vector<bool> used(N); // 現在の経路に含まれる街
    for (int i = 0; i < N; i++) {
        stk.push({i, 0, 0});
        while (!stk.empty()) {
            auto [tgt_v, tgt_dist, tgt_depth] = stk.top(); stk.pop();

            while (tgt_depth < route.size()) {
                used[route.top()] = false;
                route.pop();
            }
            route.push(tgt_v);
            used[tgt_v] = true;

            if (max_dist < tgt_dist) {
                max_dist = tgt_dist;
            }
            for (auto [next_v, next_weight] : G[tgt_v]) {
                if (used[next_v]) {
                    continue;
                }
                stk.push({next_v, tgt_dist + next_weight, tgt_depth + 1});
            }
        }
    }
    cout << max_dist << endl;
    return 0;
}
/*
別の、stackを使ったやり方に挑戦する。
解説(再帰実装)の非再帰版を作るイメージ。
*/
