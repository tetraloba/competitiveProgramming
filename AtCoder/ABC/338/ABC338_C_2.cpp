// 2024/02/19 16:05:44
// 2024/02/19 17:09:14 RE,WA
// 2024/02/19 17:19:34 RE
// 2024/02/19 18:05:55 AC.
#include <iostream>
#include <vector>
#define MAX 1000000
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> Q(N), A(N), B(N);
    for (int &q : Q) cin >> q;
    for (int &a : A) cin >> a;
    for (int &b : B) cin >> b;

    /* a の最大値 max_a を求める */
    int max_a = MAX;
    for (int i = 0; i < N; i++) {
        int tmp_max_a = A[i] ? Q[i] / A[i] : MAX;
        max_a = max_a < tmp_max_a ? max_a : tmp_max_a;
    }
    /* a の取りうる値を全探索 */
    int ans = 0;
    for (int a = 0; a <= max_a; a++) {
        int b = MAX;
        for (int i = 0; i < N; i++) {
            int tmp_b = B[i] ? (Q[i] - A[i] * a) / B[i] : MAX;
            b = tmp_b < b ? tmp_b : b;
        }
        ans = ans < a + b ? a + b : ans;
    }
    cout << ans << endl;
    return 0;
}