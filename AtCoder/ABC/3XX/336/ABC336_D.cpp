// 2024/02/23 22:09:09
// 2024/02/23 22:24:32 WA
// 2024/02/23 22:30:10 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &a: A) {
        cin >> a;
    }
    vector<int> L(N), R(N);
    int cnt_l = 0;
    for (int i = 0; i < N; i++) {
        if (cnt_l < A[i]) {
            cnt_l++;
        } else {
            cnt_l = A[i];
        }
        L[i] = cnt_l;
    }
    int cnt_r = 0;
    for (int i = N - 1; 0 <= i; i--) {
        if (cnt_r < A[i]) {
            cnt_r++;
        } else {
            cnt_r = A[i];
        }
        R[i] = cnt_r;
    }

    // // for debug
    // for (int l : L) {
    //     cout << l << ' ';
    // }
    // cout << endl;
    // for (int r : R) {
    //     cout << r << ' ';
    // }
    // cout << endl;

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int tmp = min(L[i], R[i]);
        ans = max(tmp, ans);
    }
    cout << ans << endl;
    return 0;
}