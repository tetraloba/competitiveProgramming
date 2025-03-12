// 2025/03/12 20:03:55
// 2025/03/12 20:46:28 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int HOLE = 5;
struct Txa {
    int t;
    int x;
    int a;
};
int diff(int a, int b) {
    return a < b ? b - a : a - b;
}
int main() {
    int N;
    cin >> N;
    vector<Txa> txas;
    txas.push_back({0, 0, 0});
    for (int i = 0; i < N; i++) {
        int t, x, a;
        cin >> t >> x >> a;
        txas.push_back({t, x, a});
    }
    vector<vector<long long>> dp(N + 1, vector<long long>(HOLE, -1));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < HOLE; j++) {
            for (int k = 0; k < HOLE; k++) {
                if (txas[i + 1].t - txas[i].t < diff(j, k)) {
                    continue;
                }
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][k]);
            }
        }
        if (dp[i + 1][txas[i + 1].x] == -1) {
            continue;
        }
        dp[i + 1][txas[i + 1].x] += txas[i + 1].a;
    }

    /* debug */
    // for (int i = 0; i <= N; i++) {
    //     for (int j = 0; j < HOLE; j++) {
    //         cerr << dp[i][j] << ' ';
    //     }
    //     cerr << endl;
    // }

    cout << *max_element(dp[N].begin(), dp[N].end()) << endl;
    return 0;
}
/*
座標が5つしかないのか。各時刻についてTの場所を5通りをDPすれば良いわけね。(2025/03/12 20:07:17)
*/
