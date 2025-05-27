// 2023/11/04 20:20:17
// 2023/11/04 20:21:18 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    string S;
    cin >> S;
    for (int i = 1; i < S.length(); i += 2) {
        if (S[i] != '0') {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}