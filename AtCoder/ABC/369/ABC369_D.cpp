// 2024/11/25 11:32:02
// 2024/11/25 11:46:25 AC.
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
    vector<pair<long long, long long>> dp(N);
    dp[0] = {0, A[0]};
    for (int i = 1; i < N; i++) {
        dp[i].first = max(dp[i - 1].first, dp[i - 1].second + A[i] * 2);
        dp[i].second = max(dp[i - 1].second, dp[i - 1].first + A[i]);
    }
    cout << max(dp[N - 1].first, dp[N - 1].second) << endl;
    return 0;
}
/*
動的計画法、だよな？(2024/11/25 11:33:44)
ゆっくり考えるか～
偶数と奇数の2 x Nフェーズ で良いのか。完全に理解した。(2024/11/25 11:37:20)
*/
/*
おお、解けてよかったDP…
*/
