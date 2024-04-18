// 2024/04/18 17:36:50
// 2024/04/18 20:21:42 AC.
#include <iostream>
#include <vector>
using namespace std;
pair<int, int> rotate(pair<int, int> pos, int r) {
    switch (r) {
        case 0:
            return {pos.first, pos.second};
        case 1:
            return {3 - pos.second, pos.first};
        case 2:
            return {3 - pos.first, 3 - pos.second};
        case 3:
            return {pos.second, 3 - pos.first};
    }
    return {-1, -1};
}
int main(){
    // string P[3][4];
    vector<vector<string>> P(3, vector<string>(4));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> P[i][j];
        }
    }
    pair<int, int> offset[3][2]; // 上下、左右
    // vector<vector<pair<int, int>>> offset(3, vector<pair<int, int>>(2)); // 上下、左右
    for (int i = 0; i < 3; i++) {
        bool pre = true;
        for (int r = 0; r < 4; r++) {
            int cnt = 0;
            for (int c = 0; c < 4; c++) {
                if (P[i][r][c] == '.') {
                    cnt++;
                }
            }
            if (cnt == 4) {
                if (pre) {
                    offset[i][0].first--;
                } else {
                    offset[i][0].second++;
                }
            } else {
                pre = false;
            }
        }
        pre = true;
        for (int c = 0; c < 4; c++) {
            int cnt = 0;
            for (int r = 0; r < 4; r++) {
                if (P[i][r][c] == '.') {
                    cnt++;
                }
            }
            if (cnt == 4) {
                if (pre) {
                    offset[i][1].first--;
                } else {
                    offset[i][1].second++;
                }
            } else {
                pre = false;
            }
        }
    }

    /* debug */
    // for (int i = 0; i < 3; i++) {
    //     cout << offset[i][0].first << ' ' << offset[i][0].second << ' ' << offset[i][1].first << ' ' << offset[i][1].second << endl;
    // }

    for (int rotate_seed = 0; rotate_seed < 64; rotate_seed++) {
        int offset_r[3], offset_c[3];
        for (offset_r[0] = offset[0][0].first; offset_r[0] <= offset[0][0].second; offset_r[0]++) {
            for (offset_c[0] = offset[0][1].first; offset_c[0] <= offset[0][1].second; offset_c[0]++) {
                for (offset_r[1] = offset[1][0].first; offset_r[1] <= offset[1][0].second; offset_r[1]++) {
                    for (offset_c[1] = offset[1][1].first; offset_c[1] <= offset[1][1].second; offset_c[1]++) {
                        for (offset_r[2] = offset[2][0].first; offset_r[2] <= offset[2][0].second; offset_r[2]++) {
                            for (offset_c[2] = offset[2][1].first; offset_c[2] <= offset[2][1].second; offset_c[2]++) {
                                int board[4][4] = {0};
                                // int board[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
                                for (int i = 0; i < 3; i++) {
                                    for (int r = -offset[i][0].first; r < 4 - offset[i][0].second; r++) {
                                        for (int c = -offset[i][1].first; c < 4 - offset[i][1].second; c++) {
                                            // cout << i << ' ' << r << ' ' << c << endl; // debug
                                            if (P[i][r][c] == '#') {
                                                auto [f, s] = rotate({r + offset_r[i], c + offset_c[i]}, (rotate_seed >> (i * 2)) & 3);
                                                board[f][s]++;
                                                // if (i == 0) { // debug
                                                //     board[f][s]++;
                                                // }
                                            }
                                        }
                                    }
                                }
                                bool complete = true;
                                for (int r = 0; r < 4; r++) {
                                    for (int c = 0; c < 4; c++) {
                                        // cout << board[r][c]; // debug
                                        if (board[r][c] != 1) {
                                            complete = false;
                                        }
                                    }
                                    // cout << endl; // debug
                                }
                                if (complete) {
                                    cout << "Yes" << endl;
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
/*
制約非常に緩いから全探索できない？(2024/04/18 17:41:01)
*/
