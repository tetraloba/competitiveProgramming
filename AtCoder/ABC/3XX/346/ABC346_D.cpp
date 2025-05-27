// 2024/03/25 21:11:51
// 2024/03/25 21:52:47 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<int> C(N);
    for (int &c : C) {
        cin >> c;
    }

    vector<long long> cost_sum_l0(N), cost_sum_l1(N), cost_sum_r0(N), cost_sum_r1(N);
    cost_sum_l0[0] = S[0] == '0' ? 0 : C[0];
    for (int i = 1; i < N; i++) {
        cost_sum_l0[i] = S[i] == ('0' + i % 2) ? cost_sum_l0[i - 1] : cost_sum_l0[i - 1] + C[i];
    }
    cost_sum_l1[0] = S[0] == '1' ? 0 : C[0];
    for (int i = 1; i < N; i++) {
        cost_sum_l1[i] = S[i] == ('1' - i % 2) ? cost_sum_l1[i - 1] : cost_sum_l1[i - 1] + C[i];
    }
    cost_sum_r0[N - 1] = S[N - 1] == '0' ? 0 : C[N - 1];
    for (int i = 1; i < N; i++) {
        cost_sum_r0[N - 1 - i] = S[N - 1 - i] == ('0' + i % 2) ? cost_sum_r0[N - 1 - i + 1] : cost_sum_r0[N - 1 - i + 1] + C[N - 1 - i];
    }
    cost_sum_r1[N - 1] = S[N - 1] == '1' ? 0 : C[N - 1];
    for (int i = 1; i < N; i++) {
        cost_sum_r1[N - 1 - i] = S[N - 1 - i] == ('1' - i % 2) ? cost_sum_r1[N - 1 - i + 1] : cost_sum_r1[N - 1 - i + 1] + C[N - 1 - i];
    }

    // /* debug */
    // for (long long i : cost_sum_l0) {
    //     cout << i << ' ';
    // }
    // cout << endl;
    // for (long long i : cost_sum_l1) {
    //     cout << i << ' ';
    // }
    // cout << endl;
    // for (long long i : cost_sum_r0) {
    //     cout << i << ' ';
    // }
    // cout << endl;
    // for (long long i : cost_sum_r1) {
    //     cout << i << ' ';
    // }
    // cout << endl;

    long long ans = INT64_MAX;
    if (N % 2) {
        /* Nが奇数の時。両端は異なる数字。 */
        /* 左端が0の時 */
        for (int i = 0; i < N - 1; i++) {
            long long cost = cost_sum_l0[i] + cost_sum_r1[i + 1];
            if (cost < ans) {
                ans = cost;
                // cout << ans << " at " << cost_sum_l0[i] << cost_sum_r1[i + 1] << endl; // debug
            }
        }
        /* 左端が1の時 */
        for (int i = 0; i < N - 1; i++) {
            long long cost = cost_sum_l1[i] + cost_sum_r0[i + 1];
            if (cost < ans) {
                ans = cost;
                // cout << ans << " at " << cost_sum_l1[i] << cost_sum_r0[i + 1] << endl; // debug
            }
        }
    } else {
        /* Nが偶数の時。両端は同じ数字。 */
        /* 左端が0の時 */
        for (int i = 0; i < N - 1; i++) {
            long long cost = cost_sum_l0[i] + cost_sum_r0[i + 1];
            if (cost < ans) {
                ans = cost;
                // cout << ans << " at " << cost_sum_l0[i] << cost_sum_r0[i + 1] << endl; // debug
            }
        }
        /* 左端が1の時 */
        for (int i = 0; i < N - 1; i++) {
            long long cost = cost_sum_l1[i] + cost_sum_r1[i + 1];
            if (cost < ans) {
                ans = cost;
                // cout << ans << " at " << cost_sum_l1[i] << cost_sum_r1[i + 1] << endl; // debug
            }
        }
    }
    cout << ans << endl;
    return 0;
}
/*
左右から決めていく、累積和の挟み撃ちみたいなやつかな。(2024/03/25 21:14:19)
Nが偶数の場合は両端が同じ数字
Nが奇数の場合は両端が異なる数字
それぞれ2パターンずつやらねばならないか？(2024/03/25 21:15:18)
l0 r1
01010
10101

00101

00011
*/
