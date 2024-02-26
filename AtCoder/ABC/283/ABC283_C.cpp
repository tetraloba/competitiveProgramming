// 2024/02/26 17:01:16
// 2024/02/26 17:03:56 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    string S;
    cin >> S;
    int ans = S.size();
    for (int i = 0; i < S.size(); i++) {
        if (i != S.size() - 1 && S[i] == '0' && S[i + 1] == '0') {
            ans--;
            i++;
        }
    }
    cout << ans << endl;
    return 0;
}