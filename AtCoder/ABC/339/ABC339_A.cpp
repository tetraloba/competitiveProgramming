// 2024/02/03 22:53:25
// 2024/02/03 23:01:58 AC.
#include <iostream>
#include <string>
using namespace std;
int main(){
    string S;
    cin >> S;
    for (int i = S.rfind('.') + 1; i < S.length(); i++) {
        putchar(S[i]);
    }
    return 0;
}