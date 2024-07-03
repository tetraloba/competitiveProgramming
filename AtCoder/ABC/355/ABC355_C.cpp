// 2024/07/03 21:27:01
// 2024/07/03 21:45:50 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, T;
    cin >> N >> T;
    vector<int> A(T);
    for (int &a : A) {
        cin >> a;
        a--;
    }
    vector<int> C(N, N), R(N, N);
    int diago = N, diagoR = N;

    for (int i = 0; i < T; i++) {
        int r = A[i] / N;
        int c = A[i] % N;
        R[r]--; // 行
        C[c]--; // 列
        /* 対角線 */
        if (r == c) {
            diago--;
        }
        if (r + c == N - 1) {
            diagoR--;
        }
        // cout << R[r] << ' ' << C[c] << ' ' << diago << ' ' << diagoR << endl; // debug
        if (!R[r] || !C[c] || !diago || !diagoR) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
/*
4 0 7 8 6
0 1 2
3 4 5
6 7 8
*/
