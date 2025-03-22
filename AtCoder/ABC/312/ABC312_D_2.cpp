// 2025/03/22 19:43:56
// 2025/03/22 20:14:54 AC.
#include <iostream>
#include <vector>
#define NUM 998244353
using namespace std;
int main(){
    string S;
    cin >> S;
    vector<vector<long long>> dp(S.size() + 1, vector<long long>(S.size() + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= S.size(); i++) {
        if (S[i - 1] == '(') {
            for (int j = 1; j <= S.size(); j++) {
                dp[i][j] = dp[i - 1][j - 1];
            }
        } else if (S[i - 1] == ')') {
            for (int j = 0; j < S.size(); j++) {
                dp[i][j] = dp[i - 1][j + 1];
            }
        } else if (S[i - 1] == '?') {
            dp[i][0] = dp[i - 1][1];
            dp[i][S.size()] = dp[i - 1][S.size() - 1];
            for (int j = 1; j < S.size(); j++) {
                dp[i][j] += dp[i - 1][j - 1];
                dp[i][j] %= NUM;
                dp[i][j] += dp[i - 1][j + 1];
                dp[i][j] %= NUM;
            }
        }
    }

    /* debug */
    // for (int i = 0; i <= S.size(); i++) {
    //     cerr << i <<'\t';
    //     for (int j = 0; j <= S.size(); j++) {
    //         cerr << dp[i][j] << ' ';
    //     }
    //     cerr << endl;
    // }

    cout << dp[S.size()][0] << endl;
    return 0;
}
/*
 (???(?
0010202
1102020
2010305
3001030
4000104
5000010
6000001
こうか！(2025/03/22 19:51:48)
これはDPなのか・・・？(2025/03/22 19:53:18)
*/
