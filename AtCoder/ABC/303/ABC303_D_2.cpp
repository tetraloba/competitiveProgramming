// 2025/03/18 22:50:19
// 2025/03/18 23:25:38 AC.
#include <iostream>
#include <vector>
using namespace std;
bool is_uc(char c) {
    return c == 'A';
}
int main() {
    int X, Y, Z;
    cin >> X >> Y >> Z;
    string S;
    cin >> S;
    vector<vector<long long>> dp(S.size() + 1, vector<long long>(2, INT64_MAX));
    dp[0][0] = 0;
    dp[0][1] = Z; 
    for (int i = 1; i <= S.size(); i++) {
        bool uc = is_uc(S[i - 1]);
        if (uc) {
            dp[i][0] = min(dp[i][0], dp[i - 1][0] + Y);
            dp[i][0] = min(dp[i][0], dp[i - 1][0] + Z + X + Z);
            dp[i][0] = min(dp[i][0], dp[i - 1][1] + Z + Y);
            dp[i][0] = min(dp[i][0], dp[i - 1][1] + X + Z);
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + Z + X);
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + Y + Z);
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + X);
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + Z + Y + Z);
        } else {
            dp[i][0] = min(dp[i][0], dp[i - 1][0] + X);
            dp[i][0] = min(dp[i][0], dp[i - 1][0] + Z + Y + Z);
            dp[i][0] = min(dp[i][0], dp[i - 1][1] + Z + X);
            dp[i][0] = min(dp[i][0], dp[i - 1][1] + Y + Z);
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + X + Z);
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + Z + Y);
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + Y);
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + Z + X + Z);
        }
    }
    
    /* debug */
    // for (int i = 0; i <= S.size(); i++) {
    //     cerr << dp[i][0] << ' ' << dp[i][1] << endl;
    // }

    cout << min(dp[S.size()][0], dp[S.size()][1]) << endl;
    return 0;
}
