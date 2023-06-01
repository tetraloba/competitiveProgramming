//2022/08/30 07:40:36
//2022/08/30 07:46:51 WA
//2022/08/30 08:08:24 AC.
//ABC071_B - Not Found
#include <iostream>
#include <vector>
using namespace std;
int main(){
    string S;
    cin >> S;
    int F = 0;
    int N = S.size();
    for (int i = 0; i < N; i++) {
        F |= 1 << S[i] - 'a';
    }
    for (int i = 0; i < 26; i++) {
        if (!(F & 1 << i)) {
            cout << (char)('a' + i) << endl;
            return 0;
        }
    }
    cout << "None" << endl;
    return 0;
}