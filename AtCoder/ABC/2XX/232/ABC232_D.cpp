// 2024/05/06 17:14:04
// 2024/05/06 17:27:28 AC.
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main(){
    int H, W;
    cin >> H >> W;
    vector<string> C(H);
    for (string &c : C) {
        cin >> c;
    }
    vector<vector<int>> dp(H, vector<int>(W));
    if (C[0][0] == '#') {
        cout << 0 << endl;
        return 0;
    }
    dp[0][0] = 1;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (dp[h][w] == 0) {
                continue;
            }
            if (w + 1 < W && C[h][w + 1] == '.') {
                dp[h][w + 1] = dp[h][w] + 1;
            }
            if (h + 1 < H && C[h + 1][w] == '.') {
                dp[h + 1][w] = dp[h][w] + 1;
            }
        }
    }
    int ans = 0;
    for (auto v : dp) {
        for (int i : v) {
            ans = max(i, ans);
        }
    }
    cout << ans << endl;
    return 0;
}
/*
配るDPっぽい書き方をしてみたのだけれど。
*/
