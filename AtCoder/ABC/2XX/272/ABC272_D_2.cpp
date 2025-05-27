// 2024/05/03 18:07:19
// 2024/05/03 18:39:28 23WA
// 2024/05/03 18:58:16 AC
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;

    vector<int> sqnums, seeds;
    for (int i = 0; i * i <= M; i++) {
        sqnums.push_back(i * i);
        seeds.push_back(i);
    }
    sqnums.push_back(INT32_MAX); // センチネル
    seeds.push_back(INT32_MAX);
    vector<pair<int, int>> dirs;
    for (int i  : seeds) {
        int sq_j = M - i * i;
        int j_idx = lower_bound(sqnums.begin(), sqnums.end(), sq_j) - sqnums.begin();
        // cout << i << ' ' << sq_j << ' ' << j_idx << ' ' << sqnums[j_idx] << ' ' << sqnums.size() << endl; // debug
        if (sqnums[j_idx] == sq_j) {
            int j = seeds[j_idx];
            dirs.push_back({i, j});
            dirs.push_back({-i, j});
            dirs.push_back({-i, -j});
            dirs.push_back({i, -j});
            dirs.push_back({j, i});
            dirs.push_back({-j, i});
            dirs.push_back({-j, -i});
            dirs.push_back({j, -i});
        }
    }
    // /* debug */
    // for (auto d : dirs) {
    //     cout << d.first << ' ' << d.second << endl;
    // }

    vector<vector<int>> vv(N, vector<int>(N, INT32_MAX));
    queue<pair<pair<int, int>, int>> que;
    vv[0][0] = 0;
    que.push({{0, 0}, 1});
    while (!que.empty()) {
        auto [tgt, num] = que.front(); que.pop();
        for (auto dir : dirs) {
            pair<int, int> next = {tgt.first + dir.first, tgt.second + dir.second};
            if (next.first < 0 || N <= next.first || next.second < 0 |  N <= next.second) {
                continue;
            }
            if (vv[next.first][next.second] != INT32_MAX) {
                continue;
            }
            vv[next.first][next.second] = num;
            que.push({next, num + 1});
        }
    }

    for (auto v : vv) {
        for (int i : v) {
            cout << (i == INT32_MAX ? -1 : i) << ' ';
        }
        cout << endl;
    }
    return 0;
}
