// 2023/06/02 22:39:35
// 2023/06/02 22:44:08 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    string S[8];
    for (int i = 0; i < 8; i++) {
        cin >> S[i];
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (S[i][j] == '*') {
                cout << (char)(j + 'a') << 8 - i << endl;
            }
        }
    }
    return 0;
}