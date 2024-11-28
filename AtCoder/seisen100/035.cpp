// DPL_1_B - 0,1ナップザック問題
// 2024/11/28 14:01:13
// 2024/11/28 14:25:55 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, W;
    cin >> N >> W;
    // O(NW) = O(10^6)
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, -1));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        int v, w;
        cin >> v >> w;
        for (int j = 0; j <= W; j++) {
            if (dp[i][j] == -1) {
                continue;
            }
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (W < j + w) {
                continue;
            }
            dp[i + 1][j + w] = max(dp[i + 1][j + w], dp[i][j] + v);
        }
    }
    // /* debug */
    // for (int i = 0; i <= N; i++) {
    //     for (int j = 0; j <= W; j++) {
    //         cerr << dp[i][j] << '\t';
    //     }
    //     cerr << endl;
    // }
    cout << *max_element(dp[N].begin(), dp[N].end()) << endl;
    return 0;
}
