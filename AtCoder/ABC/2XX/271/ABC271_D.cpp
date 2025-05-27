// 2025/03/04 20:55:19
// 2025/03/04 21:34:52 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node {
    bool possible;
    Node *pre_ptr;
    char ht; // 'H' or 'T'
};
string ans_str(Node head) {
    Node *tgt_ptr = &head;
    string ans;
    while (true) {
        if (tgt_ptr->ht == '\0') {
            break;
        }
        ans.push_back(tgt_ptr->ht);
        tgt_ptr = tgt_ptr->pre_ptr;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main() {
    int N, S;
    cin >> N >> S;
    vector<pair<int, int>> AB(N);
    for (auto &ab : AB) {
        cin >> ab.first >> ab.second;
    }
    vector<vector<Node>> dp(N + 1, vector<Node>(S + 1));
    dp[0][0] = {true, nullptr, '\0'};
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= S; j++) {
            if (0 <= j - AB[i - 1].first && dp[i - 1][j - AB[i - 1].first].possible) {
                dp[i][j] = {true, &dp[i - 1][j - AB[i - 1].first], 'H'};
            } else if (0 <= j - AB[i - 1].second && dp[i - 1][j - AB[i - 1].second].possible) {
                dp[i][j] = {true, &dp[i - 1][j - AB[i - 1].second], 'T'};
            }
        }
    }
    // for (int i = 0; i <= N; i++) {
    //     for (int j = 0; j <= S; j++) {
    //         cerr << (dp[i][j].possible ? 'Y' : 'N') << ' ';
    //     }
    //     cerr << endl;
    // }
    cout << (dp[N][S].possible ? "Yes\n" + ans_str(dp[N][S]) : "No") << endl;
    return 0;
}
/*
完全にDPだ。(2025/03/04 20:56:27)
*/
/*
解説は賢く辿っていますねえ。無駄にポインタ使うのやめましょう。。。
*/
