// 2025/12/14 03:08:55
// 2025/12/14 03:56:38 AC.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

pair<int, int> DIR4[] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
bool inrange(vector<vector<char>>& A, int h, int w) {
    return 0 <= h && h < A.size() && 0 <= w && w < A[0].size();
}
bool can_move_to(vector<vector<char>>& A, int h, int w, bool reverse) {
    return inrange(A, h, w) && A[h][w] != '#' && (reverse || A[h][w] != 'x') && (!reverse || A[h][w] != 'o');
}

int main() {
    /* input */
    int H, W;
    cin >> H >> W;
    vector<vector<char>> A(H, vector<char>(W));
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            cin >> A[h][w];
        }
    }

    /* pre process */
    pair<int, int> start_pos, goal_pos;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (A[h][w] == 'S') {
                start_pos = {h, w};
            }
            if (A[h][w] == 'G') {
                goal_pos = {h, w};
            }
        }
    }
    vector<vector<vector<int>>> multiD(2, vector<vector<int>>(H, vector<int>(W, INT32_MAX))); // A[i][j]に移動するのに必要な最小の操作回数(スイッチを偶数回押した表盤面と奇数回押した裏盤面を多重化)
    multiD[0][start_pos.first][start_pos.second] = 0;

    /* BFS */
    queue<pair<bool, pair<int, int>>> que; // {reverse, {h, w}}
    que.push({false, start_pos});
    while (!que.empty()) {
        auto [rev, hw] = que.front(); que.pop();
        auto [h, w] = hw;
        for (auto [dh, dw] : DIR4) {
            int nh = h + dh, nw = w + dw;
            if (!can_move_to(A, nh, nw, rev)) {
                continue;
            }
            bool nr = (A[nh][nw] == '?' ? !rev : rev);
            if (multiD[rev][h][w] + 1 < multiD[nr][nh][nw]) {
                multiD[nr][nh][nw] = multiD[rev][h][w] + 1;
                que.push({nr, {nh, nw}});
            }
        }
    }

    /* debug */
    // for (int rev = 0; rev < 2; rev++) {
    //     for (int h = 0; h < H; h++) {
    //         for (int w = 0; w < W; w++) {
    //             cerr << multiD[rev][h][w] << ' ';
    //         }
    //         cerr << endl;
    //     }
    //     cerr << endl;
    // }

    /* output */
    int dG = min(multiD[0][goal_pos.first][goal_pos.second], multiD[1][goal_pos.first][goal_pos.second]);
    cout << ((dG == INT32_MAX) ? -1 : dG) << endl;
    return 0;
}
/*
2025/12/14 03:14:15
うーん、難しいことは考えずに、スイッチ状態0の時と1の時のマスは別物と考えてBFSとかか？
2025/12/14 03:15:38
うん、裏盤面みたいなのを用意すれば良いか。
*/
