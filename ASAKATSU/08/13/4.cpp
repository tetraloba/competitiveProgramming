//2022/08/13 07:56:53
//2022/08/13 09:24:39 AC.
//ABC245_C
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    int N, M;

    /* input */
    cin >> N >> M;
    vector<int> A, B(M + 1), C;
    int tmp;
    for (int i = 0; i < N + 1; i++) {
        cin >> tmp;
        A.insert(A.begin(), tmp);
    }
    for (int i = 0; i < N + M + 1; i++) {
        cin >> tmp;
        C.insert(C.begin(), tmp);
    }

    // /* >>>debug */
    // cout << "A: ";
    // for (int i = 0; i < N + 1; i++) {
    //     cout << A[i] << ' ';
    // }
    // cout << endl;
    // cout << "C: ";
    // for (int i = 0; i < N + M + 1; i++) {
    //     cout << C[i] << ' ';
    // }
    // cout << endl;
    // /* debug<<< */

    /* calc */
    for (int i = 0; i <= M; i++) {
        B[M - i] = C[i] / A[0]; // B[M - i] is r(B[i])
        C[i] -= A[0] * B[M - i]; // expect 0
        if (B[M - i]) {
            for (int j = i + 1; j <= i + N; j++) {
                C[j] -= A[j - i] * B[M - i];
            }
        }
    }

    /* output */
    for (int i = 0; i <= M; i++) {
        cout << B[i] << ' ';
    }
    cout << endl;
    return 0;
}