// 2024/11/28 14:26:37
// 2024/11/28 14:34:35 TLE
// 2024/11/28 15:11:15 答え見れば分かるけど分からん
// 2024/11/28 15:35:38 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, W;
    cin >> N >> W;
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, -1));

    // /* 配るDP */
    // dp[0][0] = 0;
    // for (int i = 0; i < N; i++) {
    //     int v, w;
    //     cin >> v, w;
    //     for (int j = 0; j <= W; j++) {
    //         if (dp[i][j] == -1) {
    //             continue;
    //         }
    //         for (int nw = 0; j + nw < W; nw += w) {
    //             dp[i + 1][j + nw] = max(dp[i + 1][j + nw], dp[i][j] + v * nw / w);
    //         }
    //     }
    // }

    /* 貰うDP */
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        int v, w;
        cin >> v >> w;
        for (int j = 0; j <= W; j++) {
            if (dp[i - 1][j] != -1) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
            if (w <= j) {
                dp[i][j] = max(dp[i][j], dp[i][j - w] + v);
            }
        }
    }

    /* debug */
    // for (int i = 0; i <= N; i++) {
    //     for (int j = 0; j <= W; j++) {
    //         cerr << dp[i][j] << '\t';
    //     }
    //     cerr << '\n';
    // }

    /* output */
    cout << *max_element(dp[N].begin(), dp[N].end()) << endl;
    return 0;
}
/*
sample 1
4 8

4 2
5 2
2 1
8 3

0 1 2 3  4  5  6  7  8
0 2 5 8 10 13 16 18 21


dp[w][i] : v
W|              max
0:  0  0  0  0    0
1:  0  0  2  0    2
2:  4  5  4  0    5
3:  6  7  7  8    8
4:  9 10 10 10   10
5: 12 13 12 13   13
6: 14 15 15 16   16
7: 17 18 18 18   18
8: 20 21 20 21   21

dp[i][w] : v (もらうDP)
     0  1  2  3  4  5  6  7  8
0    0  -  -  -  -  -  -  -  -
4/2  0  -  4  -  8  - 12  - 16
5/2  0  -  5  - 10  - 15  - 21
2/1  0  2  5  7 10 12 15 17 21
8/3  0  2  5  8 10 13 16 18 21

dp[i][w] : v (配るDP)
     0  1  2  3  4  5  6  7  8
0    0  -  -  -  -  -  -  -  -
4/2  0  -  4  -  8  - 12  - 16
5/2  0  -  5  - 10  - 15  - 20
2/1  0  2  5  7 10 12 15 17 20
8/3  0  2  5  8 10 13 16 18 21

*/
