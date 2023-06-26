// 2023/06/26 13:03:43
// 2023/06/26 13:18:55 WA
// 2023/06/26 13:23:36 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    string S, T;
    cin >> S >> T;
    if (S.size() < T.size()) {
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    bool flag;
    int i = S.size() - T.size();
    for (; 0 <= i; i--) {
        flag = true;
        for (int j = i; j < i + T.size(); j++) {
            if (S[j] != '?' && S[j] != T[j - i]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            // cerr << "found!" << endl;
            break;
        }
    }
    if (flag) {
        for (int j = 0; j < i; j++) {
            if (S[j] == '?') {
                cout << 'a';
            } else {
                cout << S[j];
            }
        }
        for (int j = 0; j < T.size(); j++) {
            cout << T[j];
        }
        for (int j = i + T.size(); j < S.size(); j++) {
            if (S[j] == '?') {
                cout << 'a';
            } else {
                cout << S[j];
            }
        }
        cout << endl;
    } else {
        cout << "UNRESTORABLE" << endl;
    }
    return 0;
}