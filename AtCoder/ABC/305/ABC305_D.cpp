// 2023/11/02 23:55:35
// 2023/11/03 00:43:05 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    /* 累積和 */
    vector<int> c_sum(N);
    c_sum[0] = 0; // cumulative_sum
    for (int i = 1; i < N; i++) {
        if (i % 2) {
            c_sum[i] = c_sum[i - 1];
        } else {
            c_sum[i] = c_sum[i - 1] + A[i] - A[i - 1];
        }
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        int ll_index = upper_bound(A.begin(), A.end(), l) - A.begin() - 1;
        int rr_index = lower_bound(A.begin(), A.end(), r) - A.begin();
        // cout << "*ll " << c_sum[ll_index] << endl;
        // cout << "*rr " << c_sum[rr_index] << endl;
        int ans = c_sum[rr_index] - c_sum[ll_index] - (ll_index % 2 ? l - A[ll_index] : 0) - (rr_index % 2 ? 0 : A[rr_index] - r);
        cout << ans << endl;
    }
    return 0;
}
//  W   S   W    S    W    S
// 0 240 720 1320 1440 1800 2160
// 0   0 480  480  600  600  960
// 480, 1920 -> 960 - 0 - 240 - 240
// 720, 1200 -> 480 - 480
// 0, 2160 -> 960 - 0
// l以下の最大値 左が偶数番目ならその値とlの差を引く
// r以上の最小値 右が偶数番目ならその値とrの差を引く
