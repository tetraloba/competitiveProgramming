// 2025/03/10 19:06:29
// 2025/03/10 19:25:51 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> X(N);
    for (int &x : X) {
        cin >> x;
    }
    vector<int> Y(N + 1);
    for (int i = 0; i < M; i++) {
        int c, y;
        cin >> c >> y;
        Y[c] = y;
    }
    vector<vector<long long>> dp(N + 1, vector<long long>(N + 1, -1));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (dp[i][j] == -1) {
                continue;
            }
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + X[i] + Y[j + 1]);
            dp[i + 1][0] = max(dp[i + 1][0], dp[i][j]);
        }
    }
    
    /* debug */
    // for (int i = 0; i <= N; i++) {
    //     for (int j = 0; j <= N; j++) {
    //         cerr << dp[i][j] << ' ';
    //     }
    //     cerr << endl;
    // }
    cout << *max_element(dp[N].begin(), dp[N].end()) << endl;
    return 0;
}
/*
dp[N][N]で配るDP？(2025/03/10 19:10:56)
*/
