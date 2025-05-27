// 2025/01/05 18:10:07
// 2025/01/05 18:42:09 15TLE
// 2025/01/05 18:48:32 AC.
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<vector<int>> A(N * 2, vector<int>(N * 2));
    for (int i = 0; i < 2 * N - 1; i++) {
        for (int j = i + 1; j < 2 * N; j++) {
            cin >> A[i][j];
        }
    }
    /* debug */
    // for (int i = 0; i < 2 * N; i++) {
    //     for (int j = 0; j < 2 * N; j++) {
    //         cerr << A[i][j] << ' ';
    //     }
    //     cerr << endl;
    // }

    int ans = 0;
    stack<pair<int,int>> stk; // 使用済み集合, 暫定楽しさ
    stk.push({0, 0});
    while (!stk.empty()) {
        auto [decision, score] = stk.top(); stk.pop();

        // cerr << score << ':';
        // for (int i = 0; i < 2 * N; i++) {
        //     cerr << (decision >> (2 * N - 1 - i) & 1) << ' ';
        // }
        // cerr << endl;

        if (decision == (1 << 2 * N) - 1) {
            ans = max(ans, score);
            continue;
        }
        int i = 0;
        while (i < 2 * N) {
            if (!(decision >> i & 1)) {
                break;
            }
            i++;
        }
        for (int j = i + 1; j < 2 * N; j++) {
            if (decision >> j & 1) {
                continue;
            }
            int new_decision = decision | 1 << i | 1 << j;
            int new_score = score ^ A[i][j];
            stk.push({new_decision, new_score});
        }
    }

    cout << ans << endl;
    return 0;
}
/*
排他的論理和・・・？？
全探索しか無くない？(無能) (2025/01/05 18:15:24)
16 * 14 * 12 * 10 * 8 * 6 * 4 * 2 = 10321920 (1e7)
上手く実装すれば間に合うか。
16^8だと2^32なので全く間に合わない。(2025/01/05 18:22:41)
*/
