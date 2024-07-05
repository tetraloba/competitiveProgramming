// 2024/07/05 17:31:15
// 
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int diff(int a, int b){
    return a < b ? b - a : a - b;
}
int main(){
    while (true) {
        int n; // 1000
        int a, b; // 0 ~ 100
        long long d; // 10^18
        cin >> n >> a >> b >> d;
        vector<pair<int, int>> W(n);
        for (auto &w : W) {
            cin >> w.first >> w.second;
        }

        map<pair<int, int>, vector<long long>> cache; // 同じ障害物に同じ向きからぶつかった場合は以降ループするのでキャッシュしておく
        for (auto w : W) {
            cache[w] = {-1, -1, -1, -1};
        }

        // 障害物全探索か各行・列ごとに二分探索か
        vector<vector<int>> x_walls(100); // 各x座標の障害物リスト
        vector<vector<int>> y_walls(100); // 各y座標の障害物リスト
        for (auto w : W) {
            x_walls[w.first].push_back(w.second);
            y_walls[w.second].push_back(w.first);
        }
        for (auto &v : x_walls) {
            sort(v.begin(), v.end());
        }
        for (auto &v : y_walls) {
            sort(v.begin(), v.end());
        }

        /* シミュレーション */
        pair<int, int> cur(a, b); // 現在位置
        int hougaku = 0; // 現在の向き (0:x正, 1:y正, 2:x負, 3:y負)
        long long dist = 0; // 累積移動距離
        /* 次にぶつかる障害物 */
        if (hougaku % 2) {
            // x軸固定、y軸移動
            auto hit_wall_y_itr = lower_bound(x_walls[cur.first].begin(), x_walls[cur.first].end(), cur.second);
            if (hougaku == 3) {
                if (hit_wall_y_itr == x_walls[cur.first].begin()) {
                    // ぶつからない
                }
                hit_wall_y_itr--;
            }
            long long next_dist = diff(cur.second, *hit_wall_y_itr);
            dist += ;
            if (!cache[{cur.first, *hit_wall_y_itr}][hougaku]) {
                // ループ処理
            }
            cache[{cur.first, *hit_wall_y_itr}][hougaku] = dist;
        } else {
            // y軸固定、x軸移動
            auto hit_wall_x_itr = lower_bound(y_walls[cur.second].begin(), y_walls[cur.second].end(), cur.first);
            if (hougaku == 2) {
                if (hit_wall_x_itr == y_walls[cur.second].begin()) {
                    // ぶつからない
                }
                hit_wall_x_itr--;
            }
            dist += diff(cur.second, *hit_wall_x_itr);
            if (!cache[{cur.first, *hit_wall_x_itr}][hougaku]) {
                // ループ処理
            }
            cache[{cur.first, *hit_wall_x_itr}][hougaku] = dist;
        }

    }
}