// 2024/11/29 13:31:03
// 2024/11/29 13:50:10 WA
// 2024/11/29 14:28:03 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        string S, T;
        cin >> S >> T;
        vector<vector<int>> dp(S.size(), vector<int>(T.size()));
        vector<bool> doneS(S.size()), doneT(T.size()); // 各文字が消費済みか (重複使用を防ぐため)
        for (int i = 0; i < S.size(); i++) {
            for (int j = 0; j < T.size(); j++) {
                if (0 < i) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                }
                if (0 < j) {
                    dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                }
                if (S[i] == T[j]) {
                    if(!doneS[i] && !doneT[j]) {
                        dp[i][j]++;
                        doneS[i] = true;
                        doneT[j] = true;
                    }
                    if (0 < i && 0 < j) {
                        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                        doneS[i] = true;
                        doneT[j] = true;
                    }
                }
            }
        }
        cout << dp[S.size() - 1][T.size() - 1] << endl;
    }
    return 0;
}
/*
O(1000x1000x20)って1s間に合うのかしら。
  a b c b d a b
b 0 1 1 1 1 1 1
d 0 1 1 1 2 2 2
c 0 1 2 2 2 2 2
a 1 1 2 2 2 3 3
b 1 2 2 3 3 3 4
a 2 2 2 3 3 4 4

  b b b
b 1 1 1 
b 1 
b 1

  x x x x x   x
  a b c c d a b
b 0 1 1 1 1 1 1 x
d 0 1 1 1 2 2 2 x
c 0 1 2 2 2 2 2 x
c 0 1 2 3 3 3 3 x
b 0 1 2 3 3 3 4 x
a 1 1 2 3 3 3 4 x

  x x
  a b a
b 0 1 1 x
b 0 1 1
a 1 1 1 x
b 1 1 1
a 1 1 2 x
*/
/*
ユーザの回答解説見る限り、斜めの処理だけで足りるっぽい。あーなるほど。S,T両方で1文字増やしたときに増えるかどうか考えれば良いのか…
端は先に0or1で求めておくと…？
いや、端は0文字で0を作って置けば良いのか。(2024/11/29 14:36:43)
0 0 0 0 0
0
0
0
0
から斜めだけ考えていく感じね。

*/
