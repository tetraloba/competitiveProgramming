//2023/05/06 09:25:21
//2023/05/06 10:09:38 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M), C(N + M);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        C[i] = A[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i];
        C[i + N] = B[i];
    }
    sort(C.begin(), C.end());
    // for (int c : C) { // debug
    //     cout << c << ' ';
    // }
    // cout << endl;
    int i = 0, j = 0;
    for (int c : C) {
        if (A[i] == c) {
            A[i] = i + j + 1;
            i++;
        } else {
            B[j] = i + j + 1;
            j++;
        }
    }
    for (int a : A) {
        cout << a << ' ';
    }
    cout << endl;
    for (int b : B) {
        cout << b << ' ';
    }
    cout << endl;
    return 0;
}