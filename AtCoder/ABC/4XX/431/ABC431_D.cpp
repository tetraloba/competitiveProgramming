// 2025/12/13 23:49:23
// 2025/12/14 00:28:52 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> W(N), H(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> W[i] >> H[i] >> B[i];
    }
    int sum_W = 0; for (int w : W) sum_W += w;
    vector<vector<long long>> DP(N + 1, vector<long long>(sum_W / 2 + 1, -1));
    DP[0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < sum_W / 2 + 1; j++) {
            DP[i + 1][j] = max(W[i] <= j ? (DP[i][j - W[i]] == -1 ? -1 : (long long)DP[i][j - W[i]] + H[i]) : -1, DP[i][j] == -1 ? -1 : (long long)DP[i][j] + B[i]);
        }
    }

    long long ans = 0;
    for (int i = 0; i < N + 1; i++) {
        for (int j = 0; j < sum_W / 2 + 1; j++) {
            // cerr << DP[i][j] << ' ';
            ans = max(ans, DP[i][j]);
        }
        // cerr << endl;
    }

    cout << ans << endl;
    return 0;
}
/*
2025/12/13 23:49:35
どう見てもDPです。
2025/12/14 00:01:55
合計の重さは常に\sum{Wi}か。だから頭に取り付けるWiの合計を半分以下にすれば良いわけね。
*/
