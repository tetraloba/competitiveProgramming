//2022/10/20 09:11:03
//2022/10/20 09:14:19 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    string S, T;
    cin >> S >> T;
    bool flag = true;
    for (int i = 0; S[i]; i++) {
        if (S[i] != T[i]) {
            flag = false;
            break;
        }
    }
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}