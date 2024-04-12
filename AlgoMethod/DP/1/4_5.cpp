// 2024/04/12 12:36:19
// 2024/04/12 12:47:49 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> dp(30);
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 4;
    for (int i = 3; i < N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    cout << dp[N - 1] << endl;
    return 0;
}
/*
1 -> 1
2 -> 2
3 -> 4 (1 * 2 + 1 * 1 + 1 * 1)
4 -> 7 (1 * 4 + 1 * 2 + 1 * 1)
5 -> 13 (7 + 4 + 2)
*/
