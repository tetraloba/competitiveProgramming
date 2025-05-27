// 2024/02/11 22:57:00
// 2024/02/11 23:13:07 WA
// 2024/02/11 23:31:47 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<long long> A(N), S(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (i) {
            S[i] = S[i - 1] + A[i];
        } else {
            S[i] = A[i];
        }
    }
    long long min = S[0];
    for (int i = 1; i < N; i++) {
        if (S[i] < min) {
            min = S[i];
        }
    }
    min = 0 < min ? 0 : min;
    cout << S[N - 1] - min << endl;
    return 0;
}