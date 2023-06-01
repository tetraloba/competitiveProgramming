//2022/12/27 22:25:30
//2022/12/27 22:30:47 AC.
#include <iostream>
using namespace std;
int main(){
    string S, T;
    cin >> S >> T;
    for (int i = 0; S[i]; i++) {
        int j = 0;
        bool flag = true;
        while (T[j]) {
            if (S[i] != T[j]) {
                flag = false;
                break;
            }
            i++;
            j++;
        }
        if (flag) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}