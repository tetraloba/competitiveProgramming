// 2024/12/02 09:42:54
// 2024/12/02 10:26:12 WA
// 2024/12/02 10:28:15 AC.
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
double dist(pair<int, int> pos1, pair<int, int> pos2){
    return sqrt((pos1.first - pos2.first) * (pos1.first - pos2.first) + (pos1.second - pos2.second) * (pos1.second - pos2.second));
}
int main(){
    int N, S, T;
    cin >> N >> S >> T;
    vector<vector<pair<int, int>>> A(N + 1, vector<pair<int, int>>(2));
    for (int i = 1; i <= N; i++) {
        cin >> A[i][0].first >> A[i][0].second >> A[i][1].first >> A[i][1].second;
    }
    vector<int> order(N + 1); // 線分を書く順番
    for (int i = 0; i <= N; i++) {
        order[i] = i;
    }
    double ans = numeric_limits<double>::max();
    do {
        /* bit全探索 */
        int maxC = pow(2, N + 2) - 1;
        for (int C = 0; C < maxC; C++) {
            double ans_con = 0;
            for (int i = 1; i <= N; i++) {
                bool dir1 = (C >> i) % 2;
                bool dir2 = (C >> i + 1) % 2;
                /* i番目線分の始点まで移動 */
                ans_con += dist(A[order[i - 1]][!dir1], A[order[i]][dir2]) / S;
                /* i番目線分の描画 */
                ans_con += dist(A[order[i]][dir2], A[order[i]][!dir2]) / T;
            }
            ans = min(ans, ans_con);
        }
    } while (next_permutation(++order.begin(), order.end()));
    cout << fixed << setprecision(8) << ans << endl;
    return 0;
}
/*
これも制約緩めの問題か。
N <= 6ということは、全部で何通り？並べ方が6!で向きが各々2通りだから
2^(6!) = 2^720 流石に無理だなｗｗ
どちら向きが早いかをO(1)とかで求められればよいが。(2024/12/02 09:50:56)
それこそDPかなって気がするんだが。(2024/12/02 09:52:07)
いや 6! x 2^6 か。720x64=46080
普通に行けそうだな。(2024/12/02 09:54:28)
*/
/*
解説2曰くbitDPというやつでより高速に解けるらしい。bitDPは知らないので学習してから考えよう。
*/
