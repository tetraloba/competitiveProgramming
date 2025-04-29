// 2025/04/29 07:46:29
// 2025/04/29 08:27:31 WA.
// 2025/04/29 09:17:07 AC.
// code_formula_2014_final_F - 100個の円
#include <iostream>
#include <vector>
using namespace std;
int main(){
    const int N = 100;
    const int W = 1500 / 2;
    vector<int> K;
    for (int i = 0; i < N; i++) {
        K.push_back(N - i); // 100, 99, 98, ..., 1
    }

    vector<pair<int, int>> ranss;
    vector<vector<char>> grid(W, vector<char>(W));
    int k = 0;
    for (int t = 0; t < W; t++) {
        for (int l = 0; l < W; l++) {
            if (N <= k) {
                break;
            }
            if (grid[t][l]) {
                continue;
            }
            int b = t + K[k], r = l + K[k];
            if (W < b || W < r) {
                continue;
            }
            if (grid[t][r]) {
                continue;
            }
            ranss.push_back({t + b, l + r});
            for (int i = t; i < b; i++) {
                for (int j = l; j < r; j++) {
                    if (grid[i][j]) {
                        cerr << "ERROR: something wrong..." << endl;
                        cerr << k << ' ' << K[k] << endl;
                        cerr << t << ' ' << b << ' ' << l << ' ' << r << endl;
                        cerr << i << ' ' << j << endl;
                        return 1;
                    }
                    grid[i][j] = K[k] % 10 + '0';
                }
            }
            k++;
            l = r - 1;
        }
    }
    /* debug */
    // for (int i = 0; i < W; i++) {
    //     for (int j = 0; j < W; j++) {
    //         cerr << (grid[i][j] ? grid[i][j] : '.');
    //     }
    //     cerr << endl;
    // }
    

    vector<pair<int, int>> anss(ranss.rbegin(), ranss.rend());
    for (auto a : anss) {
        cout << a.first << ' ' << a.second << endl;
    }    
    return 0;
}
/*
とりあえず横に何個並べられる？
(100 + 85) * 16 / 2 = 1480
これでいけるのでは。16*16で敷き詰める気で行けば十分でしょう。(2025/04/29 07:55:25)
違うわ半経か。でもまあ頑張って詰めるしか無い。中心座標は整数らしいし。(2025/04/29 07:59:53)
(200 + 180) * 10 / 2
基本的には貪欲法アプローチで行けるはずなんだ。というか円じゃなくて正方形で良くないか。(2025/04/29 08:01:45)
1500*1500のグリッドって作れるのか、計算量的に。(2025/04/29 08:02:40)
100 100
0~200, 0~200
99 300

t   l   2r  r   cx  cy
0   0   2   1   1   1
0   2   4   2   4   2
0   6   6   3   9   3
半径1で2x2マス埋めるんだから探索は750x750で十分なはずよね。(2025/04/29 08:45:45)
*/
