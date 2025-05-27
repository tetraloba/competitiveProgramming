// 2024/11/26 11:33:01
// 2024/11/26 12:07:00 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> X(N), P(N);
    for (int &x : X) {
        cin >> x;
    }
    for (int &p : P) {
        cin >> p;
    }

    /* 累積和 */
    vector<long long> comsum(N + 1);
    comsum[0] = 0;
    for (int i = 0; i < N; i++) {
        comsum[i + 1] = comsum[i] + P[i];
    }
    /* debug */
    // for (int i = 0; i < N; i++) {
    //     cerr << comsum[i] << ' ';
    // }
    // cerr << endl;

    /* クエリ */
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        int L, R;
        cin >> L >> R;
        int l_idx = lower_bound(X.begin(), X.end(), L) - X.begin();
        int r_idx = upper_bound(X.begin(), X.end(), R) - X.begin();
        cout << comsum[r_idx] - comsum[l_idx] << endl;
    }
    return 0;
}
