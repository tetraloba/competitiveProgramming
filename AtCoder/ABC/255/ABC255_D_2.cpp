// 2025/01/05 20:25:41
// 2025/01/05 20:43:24 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }

    sort(A.begin(), A.end());
    vector<long long> cumulative_sum(N + 1);
    for (int i = 0; i < N; i++) {
        cumulative_sum[i + 1] = cumulative_sum[i] + A[i];
    }
    
    for (int q = 0; q < Q; q++) {
        int X;
        cin >> X;
        int lb_idx = lower_bound(A.begin(), A.end(), X) - A.begin();
        long long opr_add = (long long)X * lb_idx - cumulative_sum[lb_idx];
        long long opr_sub = (cumulative_sum[N] - cumulative_sum[lb_idx]) - (long long)X * (N - lb_idx);
        cout << opr_add + opr_sub << endl;
    }
    return 0;
}
/*
Xより大きいやつの和とXより小さいやつの和を求められれば計算できそう。
Aはソートできるのでニブタンして・・・
累積和かな。(2025/01/05 20:31:32)
2 5 5 6 11
5
    5以上 4件 27 → 27 - 5*4 = 7
    5未満 1件 2 → 5*1 - 2 = 3
20
    20以上 0件
    20未満 5件 29 → 20*5 - 29 = 71
0
    0以上 5件 29 → 29 - 5*0 = 29
*/
