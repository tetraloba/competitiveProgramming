// 2024/04/12 12:25:17
// 2024/04/12 12:29:19 AC.
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
    vector<int> dp(N, INT32_MAX);
    dp[N - 1] = 0;
    for (int i = N - 1; 1 <= i; i--) {
        if (i != 1) {
            dp[i - 2] = min(dp[i - 2], dp[i] + A[i] * 2);
        }
        dp[i - 1] = min(dp[i - 1], dp[i] + A[i]);
    }
    cout << dp[0] << endl;
    return 0;
}
/*
ゴールから戻っていくと考える
*/
/*
2024/04/12 13:12:31
配るDPの実装になるらしい。
https://algo-method.com/descriptions/78
*/
