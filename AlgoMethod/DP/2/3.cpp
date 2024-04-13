// 2024/04/13 09:35:05
// 2024/04/13 09:57:19 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<vector<long long>> A(N, vector<long long>(3));
    for (auto &v : A) {
        for (auto &a : v) {
            cin >> a;
        }
    }
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            long long max = 0;
            for (int k = 0; k < 3; k++) {
                if (k != j && max < A[i - 1][k]) {
                    max = A[i - 1][k];
                }
            }
            A[i][j] += max;
        }
    }
    long long ans = A[N - 1][0];
    ans = ans < A[N - 1][1] ? A[N - 1][1] : ans;
    ans = ans < A[N - 1][2] ? A[N - 1][2] : ans;
    cout << ans << endl;
    return 0;
}
