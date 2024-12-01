// 第１０回日本情報オリンピック 予選（過去問） D - 1 年生 (A First Grader) https://atcoder.jp/contests/joi2011yo/tasks/joi2011yo_d
// 2024/12/01 18:14:49
// 2024/12/01 18:34:42 WA
// 2024/12/01 18:43:06 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }
    vector<vector<long long>> dp(N - 1, vector<long long>(20 + 1));
    dp[0][A[0]] = 1;
    for (int i = 1; i < N - 1; i++) {
        for (int j = 0; j <= 20; j++) {
            // dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (0 <= j - A[i]) {
                dp[i][j] += dp[i - 1][j - A[i]];
            }
            if (j + A[i] <= 20) {
                dp[i][j] += dp[i - 1][j + A[i]];
            }
        }
    }
    /* debug */
    // for (int i = 0; i < 21; i++) {
    //     cerr << i << '\t';
    // }
    // cerr << endl;
    // for (int i = 0; i < N - 1; i++) {
    //     for (int j = 0; j <= 20; j++) {
    //         cerr << dp[i][j] << '\t';
    //     }
    //     cerr << endl;
    // }

    /* output */
    cout << dp[N - 2][A[N - 1]] << endl;
    return 0;
}
/*
dp[N][20] (2024/12/01 18:16:41)
*/
