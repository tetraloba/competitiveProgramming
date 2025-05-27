//2022/12/27 22:23:16
//2022/12/27 22:25:04 AC.
#include <iostream>
using namespace std;
int main(){
    string S;
    cin >> S;
    int ans = 0;
    for (int i = 0; S[i]; i++) {
        if (S[i] == 'v') {
            ans += 1;
        } else {
            ans += 2;
        }
    }
    cout << ans << endl;
    return 0;
}