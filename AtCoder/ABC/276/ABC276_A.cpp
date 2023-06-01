//2023/01/08 11:02:40
//2023/01/08 11:03:53 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    string S;
    cin >> S;
    int ans = -1;
    for (int i = 0; S[i]; i++) {
        if (S[i] == 'a') {
            ans = i + 1;
        }
    }
    cout << ans << endl;
    return 0;
}