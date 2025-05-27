// 2024/02/26 12:32:12
// 2024/02/26 16:32:35 AC.
#include <iostream>
#include <vector>
#include <algorithm>
#define NUM 998244353
using namespace std;
int main(){
    int N, M, K;
    cin >> N >> M >> K;

    long long ans = 0;
    // K個の玉をN個の枠に入れる方法の個数
    vector<vector<long long>> KN_matrix(K + 1, vector<long long>(N + 1));
    for (int k = 1; k <= K; k++) {
        // k=0 のとき KN_matrix[k][n] = 0
        for (int n = 1; n <= N && n <= k; n++) {
            // k < n のとき KN_matrix[k][n] = 0
            // if (k == n) { // 必須ではない。以下のfor文で同義
            //     KN_matrix[k][n] = 1;
            //     continue;
            // }
            if (n == 1) {
                KN_matrix[k][n] = k <= M ? 1 : 0;
                continue;
            }
            // k = 3 n = 2のとき
            // m[3][2] = m[3][1] * m[0][1] + m[2][1] * m[1][1] + m[1][1] * m[2][1] + m[0][1] * m[3][1]
            //         = 0 + 1 + 1 + 0 = 2
            // m[4][2] = m[3][1] * m[1][1] + m[2][1] * m[2][1] + m[1][1] * m[3][1]
            //         = 1 + 1 + 1 = 3
            // m[4][3] = m[2][1] * m[2][2] + m[1][1] * m[3][2]
            // m[5][2] = m[4][1] * m[1][1] + m[3][1] * m[2][1] + m[2][1] * m[3][1] + m[1][1] * m[4][1]
            // m[5][3] = m[3][1] * m[2][2] + m[2][2] * m[3][2] + m[1][1] * m[1][2]
            for (int i = k - n + 1; 1 <= i; i--) {
                KN_matrix[k][n] += KN_matrix[i][1] * KN_matrix[k - i][n - 1];
                KN_matrix[k][n] %= NUM;
            }
        }
        // // debug
        // for (int k = 0; k <= K; k++) {
        //     for (int n = 0; n <= N; n++) {
        //         cout << k << ',' << n << ' ' << KN_matrix[k][n] << endl;
        //     }
        //     cout << endl;
        // }
        // cout << k << ' ' << KN_matrix[k][N] << endl; // debug
        ans += KN_matrix[k][N];
        ans %= NUM;
    }
    cout << ans << endl;

    return 0;
}
// メモ化して深さ優先探索とか？ (2024/02/26 15:01:16)
// 最終的に、 K個の玉をN個の枠に収める方法は何通りかを知りたい。
// k(1 <= k <= K) 個の玉を n(1 <= n <= N) 個の 枠に収める方法を K * N の表形式で管理して埋めていく？
