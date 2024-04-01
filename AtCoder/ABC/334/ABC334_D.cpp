// 2024/04/01 19:18:35
// 2024/04/01 19:27:38 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, Q;
    cin >> N >> Q;
    vector<int> R(N);
    for (int &r : R) {
        cin >> r;
    }
    sort(R.begin(), R.end());
    vector<long long> R_sum(N);
    R_sum[0] = R[0];
    for (int i = 1; i < N; i++) {
        R_sum[i] = R_sum[i - 1] + R[i];
    }
    R_sum.push_back(INT64_MAX);
    for (int i = 0; i < Q; i++) {
        long long X;
        cin >> X;
        cout << upper_bound(R_sum.begin(), R_sum.end(), X) - R_sum.begin() << endl;;
    }
    return 0;
}
/*
うーん？問題を理解していないが、ソートして累積和作ればよくね？
あー逆か。二分探索で間に合うか？
間に合いそうだよね。(2024/04/01 19:22:58)
*/
