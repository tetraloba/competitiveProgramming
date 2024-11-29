// 2024/11/29 12:48:06
// 2024/11/29 13:17:02 WA
// 2024/11/29 13:29:53 AC.
#include <iostream>
#include <vector>
#define INF (n + 1)
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> c(m);
    for (int i = 0; i < m; i++) {
        cin >> c[i];
    }
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INF)); // 中身は枚数かな
    dp[0][0] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (dp[i - 1][j] != INF) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            }
            if (c[i - 1] <= j && dp[i][j - c[i - 1]] != INF) {
                dp[i][j] = min(dp[i][j], dp[i][j - c[i - 1]] + 1);
            }
        }
    }
    /* debug */
    // for (int i = 0; i <= n; i++) {
    //     cerr << i << '\t';
    // }
    // cerr << endl;
    // for (int i = 0; i <= m; i++) {
    //     for (int j = 0; j <= n; j++) {
    //         cerr << dp[i][j] << '\t';
    //     }
    //     cerr << endl;
    // }

    /* output */
    cout << dp[m][n] << endl;
    return 0;
}
/*
まあ制約からしてO(nm)だよね。(メタ読み) (2024/11/29 12:53:08)
*/
/*
036と同じかな。もらうDPで実装すれば簡単。
*/
