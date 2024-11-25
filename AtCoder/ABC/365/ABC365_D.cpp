// 2024/11/25 11:50:56
// 2024/11/25 12:21:45 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<vector<int>> dp(N, vector<int>(3)); // R, P, S
    switch (S[0]) {
        case 'R':
            dp[0][1]++;
            break;
        case 'P':
            dp[0][2]++;
            break;
        case 'S':
            dp[0][0]++;
            break;
    }
    for (int i = 1; i < N; i++) {
        switch (S[i]) {
            case 'R':
                dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]);
                dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + 1;
                dp[i][2] = 0;
                break;
            case 'P':
                dp[i][0] = 0;
                dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]);
                dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
                break;
            case 'S':
                dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + 1;
                dp[i][1] = 0;
                dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]);
                break;
        }
        // cerr << dp[i][0] << dp[i][1] << dp[i][2] << endl; // debug
    }
    cout << *max_element(dp[N - 1].begin(), dp[N - 1].end()) << endl;
    return 0;
}
/*
さっきと同様DPの匂い。(2024/11/25 11:52:05)
*/
/*
動的計画法が解けるようになったのは良いが、解説の方が圧倒的にきれいな書き方をしているので参照のこと。
> https://atcoder.jp/contests/abc365/editorial/10598
*/
