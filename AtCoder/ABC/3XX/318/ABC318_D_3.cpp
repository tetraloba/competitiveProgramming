// 2025/03/08 12:28:56
// 2025/03/08 12:50:33 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<pair<int, int>> cost_perfs(N);
    int sumZ = 0;
    for (auto &cp : cost_perfs) {
        int X, Y, Z;
        cin >> X >> Y >> Z;
        cp = {max(0, (Y - X - 1) / 2 + 1), Z};
        sumZ += Z;
    }
    vector<vector<long long>> dp(N + 1, vector<long long>(sumZ + 1, INT64_MAX));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= sumZ; j++) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            if (0 <= j - cost_perfs[i].second && dp[i][j - cost_perfs[i].second] != INT64_MAX) {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j - cost_perfs[i].second] + cost_perfs[i].first);
            }
        }
    }
    /* debug */
    // for (int i = 0; i <= N; i++) {
    //     for (int j = 0; j <= sumZ; j++) {
    //         cerr << dp[i][j] << ' ';
    //     }
    //     cerr << endl;
    // }

    long long ans = INT64_MAX;
    for (int i = sumZ / 2 + 1; i <= sumZ; i++) {
        ans = min(ans, dp[N][i]);
    }
    cout << ans << endl;
    return 0;
}
/*
ナップサック問題だねえ。(2025/03/08 12:29:55)
*/
