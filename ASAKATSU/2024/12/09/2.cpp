// ARC049_A - "強調"
// 2024/12/09 07:31:03
// 2024/12/09 07:36:25 は？
// 2024/12/09 08:23:08 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    string S;
    cin >> S;
    int A[4];
    cin >> A[0] >> A[1] >> A[2] >> A[3];
    for (int i = 0; i <= S.size(); i++) {
        for (int j = 0; j < 4; j++) {
            if (A[j] == i) {
                cout << '"';
            }
        }
        if (i < S.size()) {
            cout << S[i];
        }
    }
    cout << endl;
    return 0;
}

