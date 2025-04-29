// 2025/04/29 07:42:29
// 2025/04/29 07:46:27 AC.
// ABC040_C - 柱柱柱柱柱
#include <iostream>
#include <vector>
using namespace std;
int diff(int a, int b) {
    return a < b ? b - a : a - b;
}
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }
    vector<long long> dp(N);
    dp[1] = dp[0] + diff(A[0], A[1]);
    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i - 1] + diff(A[i - 1], A[i]), dp[i - 2] + diff(A[i - 2], A[i]));
    }
    cout << dp[N - 1] << endl;
    return 0;
}
/*
DP(2025/04/29 07:43:16)
*/
