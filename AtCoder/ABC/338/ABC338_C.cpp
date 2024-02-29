// 2024/02/19 16:05:44
// 2024/02/19 17:09:14 RE,WA
// 2024/02/19 17:19:34 RE
#include <iostream>
#include <vector>
#define LL long long int
#define MAX 1000000
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> Q(N), A(N), B(N);
    for (int &q : Q) cin >> q;
    for (int &a : A) cin >> a;
    for (int &b : B) cin >> b;

    int a, b, ans = 0;
    /* a = 0 のとき */
    a = 0;
    b = MAX;
    for (int k = 0; k < N; k++) {
        int tmp_b = B[k] ? (Q[k] - A[k] * a) / B[k] : MAX;
        b = tmp_b < b ? tmp_b : b;
    }
    ans = ans < a + b ? a + b : ans;
    /* b = 0 のとき */
    b = 0;
    a = MAX;
    for (int k = 0; k < N; k++) {
        int tmp_a = A[k] ? (Q[k] - B[k] * b) / A[k] : MAX;
        a = tmp_a < a ? tmp_a : a;
    }
    ans = ans < a + b ? a + b : ans;
    // O(C(N,2) * N)
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            LL coe_a = ((LL) A[i] * B[j] - (LL) A[j] * B[i]);
            a = coe_a ? ((LL) Q[i] * B[j] - (LL) Q[j] * B[i]) / coe_a : 0;
            b = MAX;
            for (int k = 0; k < N; k++) {
                int tmp_b = B[k] ? (Q[k] - A[k] * a) / B[k] : MAX;
                b = tmp_b < b ? tmp_b : b;
            }
            ans = ans < a + b ? a + b : ans;
        }
    }
    cout << ans << endl;
    return 0;
}