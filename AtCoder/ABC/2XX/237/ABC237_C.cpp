// 2022/08/12 19:17:11
// 2022/08/12 19:20:45 WA
// 2022/08/12 19:23:54 AC.
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main(){
    string S;
    cin >> S;
    int i = 0, j = strlen(S.c_str()) - 1;
    while (S[j] == 'a' && i < j) {
        j--;
        if (S[i] == 'a') {
            i++;
        }
    }
    bool flag = true;
    while (i < j) {
        if (S[i++] != S[j--]) {
            flag = false;
        }
    }
    if (flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}