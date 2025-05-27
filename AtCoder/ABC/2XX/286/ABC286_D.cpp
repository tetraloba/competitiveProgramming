// 2025/01/05 21:10:25
// 2025/01/05 21:42:00 AC.
#include <iostream>
#include <vector>
#define MAX INT32_MAX
using namespace std;
int main(){
    int N, X;
    cin >> N >> X;
    vector<pair<int, int>> AB(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> AB[i].first >> AB[i].second;
    }

    vector<vector<int>> dp(N + 1, vector<int>(X + 1, MAX));
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int x = 0; x <= X; x++) {
            if (dp[i - 1][x] != MAX) {
                dp[i][x] = 0;
            }
            if (x < AB[i].first) {
                continue;
            }
            // cerr << i << ',' << x << ',' << dp[i][x - AB[i].first] << endl; // debug
            if (AB[i].second <= dp[i][x - AB[i].first]) {
                continue;
            }
            dp[i][x] = min(dp[i][x], dp[i][x - AB[i].first] + 1);
        }
    }

    /* debug */
    // for (int i = 0; i <= N; i++) {
    //     for (int j = 0; j <= X; j++) {
    //         cerr << dp[i][j] << '\t';
    //     }
    //     cerr << endl;
    // }

    cout << (dp[N][X] == MAX ? "No" : "Yes") << endl;
    return 0;
}
/*
おー典型的なDPかな？(2025/01/05 21:11:20)
*/
