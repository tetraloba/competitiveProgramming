// 2024/07/05 17:31:15
// 2024/07/05 19:00頃 中断
// 2024/07/05 21:48:29 Sample Input AC
#include <iostream>
#include <vector>
#include <map>
using namespace std;

pair<long long, long long> solve(int n){
    int a, b; // 0 ~ 100
    long long d; // 10^18
    cin >> a >> b >> d;
    vector<pair<int, int>> W(n);
    for (auto &w : W) {
        cin >> w.first >> w.second;
    }

    map<pair<int, int>, vector<long long>> cache; // 同じ障害物に同じ向きからぶつかった場合は以降ループするのでキャッシュしておく
    for (auto w : W) {
        cache[w] = {-1, -1, -1, -1};
    }

    /* シミュレーション */
    pair<long long, long long> cur(a, b); // 現在位置
    int hougaku = 0; // 現在の向き (0:x正, 1:y正, 2:x負, 3:y負)

    while (d) {
        /* 次にぶつかる障害物(届かない可能性あり) */
        pair<int, int> next_wall(-1, -1);
        long long dist2wall = INT64_MAX;
        for (auto w : W) { // 障害物全探索(高速化余地あり)
            switch (hougaku) {
                case 0:
                    if (w.second != cur.second || w.first < cur.first || dist2wall < w.first - cur.first) {
                        continue;
                    }
                    next_wall = w;
                    dist2wall = w.first - cur.first - 1;
                    break;
                case 1:
                    if (w.first != cur.first || w.second < cur.second || dist2wall < w.second - cur.second) {
                        continue;
                    }
                    next_wall = w;
                    dist2wall = w.second - cur.second - 1;
                    break;
                case 2:
                    if (w.second != cur.second || cur.first < w.first || dist2wall < cur.first - w.first) {
                        continue;
                    }
                    next_wall = w;
                    dist2wall = cur.first - w.first - 1;
                    break;
                case 3:
                    if (w.first != cur.first || cur.second < w.second || dist2wall < cur.second - w.second) {
                        continue;
                    }
                    next_wall = w;
                    dist2wall = cur.second - w.second - 1;
                    break;
            }
        }
        cerr << '(' << next_wall.first << ',' << next_wall.second << ')' << dist2wall << endl; // debug

        if (d < dist2wall) {
            // 壁まで届かない
            dist2wall = d;
        }
        // cout << "roop check:" << d << endl;

        /* 現在位置と累積移動距離、向きを更新する */
        switch (hougaku) {
            case 0:
                cur.first += dist2wall;
                break;
            case 1:
                cur.second += dist2wall;
                break;
            case 2:
                cur.first -= dist2wall;
                break;
            case 3:
                cur.second -= dist2wall;
                break;
        }
        d -= dist2wall;
        hougaku = (hougaku + 1) % 4;

        if (d) {
            // 壁に届く: ループ検知とキャッシュ更新
            if (cache[next_wall][hougaku] != -1) {
                // ループ！！！
                // cerr << "LOOP!" << endl; // debug
                // return {-77777777, -77777777}; // debug
                d %= cache[next_wall][hougaku] - d; // ループの周期で剰余
            } else {
                cache[next_wall][hougaku] = d;
            }
        }

        cerr << "at " << cur.first << ' ' << cur.second << endl; // debug
    }
    return {cur.first, cur.second};
}

int main(){
    while (true) {
        int n; // 1000
        cin >> n;
        if (!n) {
            break;
        }
        auto ans = solve(n);
        cout << ans.first << ' ' << ans.second << endl;
    }
    return 0;
}
