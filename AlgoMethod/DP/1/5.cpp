// 2024/04/12 12:48:07
// 2024/04/12 13:02:08 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }
    vector<int> dp(N);
    for (int i = 1; i < N; i++) {
        dp[i] = dp[i - 1] + A[i];
        int j = 1;
        while (0 <= i - j && j <= M) {
            dp[i] = min(dp[i - j] + A[i] * j, dp[i]);
            j++;
        }
    }
    cout << dp[N - 1] << endl;
    return 0;
}
