// 2023/05/14 13:40:58
// 2023/05/14 13:46:34 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    string S;
    cin >> S;
    for (int i = 1; i <= S.length() / 2; i++) {
        char tmp = S[2 * i - 1];
        S[2 * i - 1] = S[2 * i - 1 - 1];
        S[2 * i - 1 - 1] = tmp;
    }
    cout << S << endl;
    return 0;
}