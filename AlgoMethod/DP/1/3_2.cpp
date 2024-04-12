// 2024/04/12 12:29:58
// 2024/04/12 12:33:57 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> dp(N);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 0; i < N - 1; i++) {
        dp[i + 1] += dp[i];
        if (i < N - 2) {
            dp[i + 2] += dp[i];
        }
    }
    cout << dp[N - 1] << endl;
    return 0;
}
