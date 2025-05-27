// 2023/11/09 13:07:26
// 2023/11/09 13:13:24 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int L, R;
    cin >> L >> R;
    L--;
    R--;
    string S;
    cin >> S;
    int i = 0;
    while (i < L) {
        cout << S[i++];
    }
    while (i <= R) {
        cout << S[R - (i++ - L)];
    }
    while (i < S.length()) {
        cout << S[i++];
    }
    cout << endl;
    return 0;
}