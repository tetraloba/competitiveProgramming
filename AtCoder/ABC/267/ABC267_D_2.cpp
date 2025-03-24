// 2025/03/24 20:23:14
// 2025/03/24 21:24:14 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }
    vector<vector<long long>> dp(M, vector<long long>(N, INT64_MIN)); // (i + 1)番目にjを選ぶときにあり得る最大値
    for (int i = 0; i < N; i++) {
        dp[0][i] = A[i];
    }
    for (int i = 1; i < M; i++) {
        long long max_pre = INT64_MIN;
        for (int j = 0; j < i; j++) {
            max_pre = max(max_pre, dp[i - 1][j]);
        }
        for (int j = i; j < N; j++) {
            dp[i][j] = max_pre + A[j] * (i + 1);
            max_pre = max(max_pre, dp[i - 1][j]);
        }
    }

    /* debug */
    // for (int i = 0; i < M; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cerr << dp[i][j] << ' ';
    //     }
    //     cerr << endl;
    // }

    cout << *max_element(dp[M - 1].begin(), dp[M - 1].end()) << endl;
    return 0;
}
/*
この手のやつはDPだろうなあという予感はするんだが。(2025/03/24 20:28:04)
5 4 -1 8
5 * 1 + 4 * 2 + -1 * 3 + 8 * 4 = 42
いや，選ぶ数が決まっているのか。(2025/03/24 20:31:29)
-1 8 1 みたいな場合に，大きい8,1を取るよりも，-1を取って8の係数を大きくした方が嬉しい。(2025/03/24 20:50:41)
つまり8より前の数には，選ぶことで8の係数を大きくするという価値があるわけか。
7 8 1
8 9 1 みたいなこと？後ろからの累積和分が乗る？妥当性の証明ができないが(2025/03/24 20:52:11)
-3 1 -4 1 -5  9 -2 6 -5 3
 1 4  3 7  6 11  2 4 -2 3
 X o  X O  O  O  X o  X X
1 1 -5 9 -> 1 + 2 -15 + 36 = 24
1 -5 9 6 -> 1 -10 +27 +24 = 42
全然違うじゃないか…(2025/03/24 20:56:39)

  5  4 -1  8
1 5  4 -1  8
2 - 13 -2 21
みたいな感じか？(2025/03/24 21:10:33)
   -3 1  -4  1  -5  9 -2  6 -5  3
1  -3 1  -4  1  -5  9 -2  6 -5  3
2  - -1  -7  3  -9 19  5 21  1 15
3  -  - -13  2 -12 30 13 37  6 30
4  -  -   - -9 -18 38 22 54 17 49
あーこうっぽいな。(2025/03/24 21:15:47)
 */
