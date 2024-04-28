// 2024/04/28 20:29:38
// 2024/04/28 21:28:27 AC.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
pair<int, int> DIR4[4] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
int main(){
    int H, W;
    cin >> H >> W;
    vector<string> vs(H);
    for (string &s : vs) {
        cin >> s;
    }

    int ans = 0;
    vector<int> done(1000000, INT32_MIN);
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            // /* debug */
            // for (int i = 0; i < H; i++) {
            //     for (int j = 0; j < W; j++) {
            //         cout.width(11);
            //         cout << done[i * 1000 + j] << ' ';
            //     }
            //     cout << endl;
            // }
            // cout << endl;

            if (vs[h][w] == '#') {
                continue;
            }
            if (done[h * 1000 + w] != INT32_MIN) {
                continue; // いずれかの回で処理済みなら処理しない。
            }

            int dof = 1; // degree of freedom
            queue<pair<int, int>> que;
            que.push({h, w});
            done[h * 1000 + w] = h * 1000 + w;
            while (!que.empty()) {
                pair<int, int> tgt = que.front(); que.pop();
                bool can_move = true;
                for (int d = 0; d < 4; d++) {
                    pair<int, int> neighbor = {tgt.first + DIR4[d].first, tgt.second + DIR4[d].second};
                    if (neighbor.first < 0 || H <= neighbor.first || neighbor.second < 0 || W <= neighbor.second) {
                        continue; // 範囲外は無視
                    }
                    if (vs[neighbor.first][neighbor.second] == '#') {
                        can_move = false; // マグネットと隣接している
                    }
                }
                if (!can_move) {
                    continue; // 動けない
                }
                for (int d = 0; d < 4; d++) {
                    pair<int, int> next = {tgt.first + DIR4[d].first, tgt.second + DIR4[d].second};
                    if (next.first < 0 || H <= next.first || next.second < 0 || W <= next.second) {
                        continue; // 範囲外は移動できない
                    }
                    if (h * 1000 + w == done[next.first * 1000 + next.second]) {
                        continue; // この回で処理済みなら追加しない。
                    }
                    que.push(next);
                    done[next.first * 1000 + next.second] = h * 1000 + w;
                    dof++;
                }
            }
            if (ans < dof) {
                ans = dof;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
/*
まあ、幅優先探索すればよいのかなあ。(2024/04/28 20:33:38)

.#...
.....
.#..#

5#333
55333
5#33#

*/
