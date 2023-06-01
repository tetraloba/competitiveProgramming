//2022/08/20 07:32:46
//2022/08/20 07:48:01 AC.
//ABC223_C - Doukasen
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    vector<double> sum(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        if (i) {
            sum[i] = sum[i - 1] + (double)A[i] / B[i];
        } else {
            sum[i] = (double)A[i] / B[i];
        }
    }
    // for (int i = 0; i < N; i++) {
    //     cout << A[i] << ' ' << B[i] << ' ' << sum[i] << endl;
    // }
    double ans = 0;
    for (int i = 0; i < N; i++) {
        if (sum[N - 1] / 2 <= sum[i]) {
            for (int j = 0; j < i; j++) {
                ans += A[j];
            }
            ans += B[i] * (sum[N - 1] / 2 - sum[i - 1]);
            break;
        }
    }
    cout << fixed << ans << endl;
    return 0;
}