// 第１１回日本情報オリンピック 予選（過去問） D - パスタ (Pasta) https://atcoder.jp/contests/joi2012yo/tasks/joi2012yo_d
// 2024/12/01 18:44:01
// 2024/12/01 20:07:57 AC.
#include <iostream>
#include <vector>
#define MOD 10000
using namespace std;
int main(){
    /* input */
    int N, K;
    cin >> N >> K;
    vector<vector<long long>> dp(N, vector<long long>(3 * 3));
    const vector<vector<int>> tgts = {{3, 6}, {0, 3, 6}, {0, 3, 6}, {1, 4, 7}, {1, 7}, {1, 4, 7}, {2, 5, 8}, {2, 5, 8}, {2, 5}}; // dp[i][j]がdp[i - 1]から貰う対象のリスト
    vector<long long> sum(N);
    vector<int> dec(N, -1);
    for (int i = 0; i < K; i++) {
        int A, B;
        cin >> A >> B;
        A--; B--;
        dec[A] = B;
    }

    /* day0, day1 の初期化 (もう少しきれいにも書けるが、とりあえず) */
    if (dec[0] == -1) {
        if (dec[1] == -1) {
            for (int i = 0; i < 9; i++) {
                dp[1][i] = 1;
            }
            sum[1] = 9;
        } else {
            for (int i = 0; i < 9; i++) {
                if (i % 3 == dec[1]) {
                    dp[1][i] = 1;
                } else {
                    dp[1][i] = 0;
                }
            }
            sum[1] = 3;
        }
    } else {
        if (dec[1] == -1) {
            for (int i = 0; i < 9; i++) {
                if (i / 3 == dec[0]) {
                    dp[1][i] = 1;
                } else {
                    dp[1][i] = 0;
                }
            }
            sum[1] = 3;
        } else {
            for (int i = 0; i < 9; i++) {
                if (i / 3 == dec[0] && i % 3 == dec[1]) {
                    dp[1][i] = 1;
                } else {
                    dp[1][i] = 0;
                }
            }
            sum[1] = 1;
        }
    }
    /* day2以降 */
    for (int i = 2; i < N; i++) {
        for (int j = 0; j < 9; j++) {
            if (dec[i] == -1) {
                long long tmp_ij = 0;
                for (int tgt : tgts[j]) { // O(2~3)
                    dp[i][j] += dp[i - 1][tgt];
                    dp[i][j] %= MOD;
                }
            } else {
                if (j % 3 == dec[i]) {
                    for (int tgt : tgts[j]) {
                        dp[i][j] += dp[i - 1][tgt];
                        dp[i][j] %= MOD;
                    }
                }
            }
            sum[i] += dp[i][j];
            sum[i] %= MOD;
        }
    }

    /* debug */
    for (int i = 0; i < N; i++) {
        cerr << "day" << i << '\t';
        for (int j = 0; j < 9; j++) {
            cerr << dp[i][j] << '\t';
        }
        cerr << '(' << sum[i] << ')';
        cerr << endl;
    }
    
    /* output */
    cout << sum[N - 1] << endl;
    return 0;
}
/*
    0  1  2
 0  1  1  1
 1  3  3  3  // 00 01 02
 2  8  8  8  // 010 020 100 110 120 200 210 220

022
122

前2つを保存して9通り要るのか。(2024/12/01 19:35:00)
  00 01 02 10 11 12 20 21 22
0  
1  1  1  1  1  1  1  1  1  1
2  2  3  3  3  2  3  3  3  2  24
3  6  8  8  8  6  8  8  8  6  66
...

貰う対象は
 0  1  2  3  4  5  6  7  8
00 01 02 10 11 12 20 21 22
として
{{3, 6}, {0, 3, 6}, {0, 3, 6}, {1, 4, 7}, {1, 7}, {1, 4, 7}, {2, 5, 8}, {2, 5, 8}, {2, 5}}
と定義できるかな。(2024/12/01 19:43:39)

*/
