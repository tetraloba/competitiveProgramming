//2022/08/15 13:44:26
//2022/08/15 13:46:42 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int X, Y, Z;
    cin >> X >> Y >> Z;
    vector<int> A(X), B(Y), C(Z);
    for (int i = 0; i < X; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < Y; i++) {
        cin >> B[i];
    }
    for (int i = 0; i < Z; i++) {
        cin >> C[i];
    }
    int cnt = 0;
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            for (int k = 0; k < Z; k++) {
                if (A[i] + B[j] == C[k]) {
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}