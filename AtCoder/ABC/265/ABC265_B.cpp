//2022/08/21 21:03:43
//2022/08/21 21:11:31 RE
//2022/08/21 21:14:07 WA
//2022/08/21 21:37:00 AC. Tがオーバーフローするんやな・・・・
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, M;
    long long T;
    cin >> N >> M >> T;
    vector<int> A(N), X(M), Y(M);
    for (int i = 0; i < N - 1; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> X[i]>> Y[i];
    }
    // cout << '$';
    int j = 0;
    for (int i = 0; i < N - 1; i++) {
        if (j < M && i == X[j] - 1) {
            T += Y[j];
            j++;
        }
        // cout << '#';
        if (A[i] < T) {
            T -= A[i];
        } else {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}