//2022/08/05 07:30:13
//2022/08/05 07:34:36 AC.
#include <iostream>
using namespace std;
int main(){
    char S[3][11], T[1001];
    cin >> S[0] >> S[1] >> S[2] >> T;
    for (int i = 0; T[i]; i++) {
        cout << S[T[i] - '1'];
    }
    cout << '\n';
    return 0;
}