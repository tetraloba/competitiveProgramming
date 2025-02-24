// 2025/02/24 11:27:45
// 2025/02/24 11:30:26 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    string S;
    cin >> S;
    int ans = 0;
    int cnt = 0;
    for (char c : S) {
        if (c == 'A' || c == 'C' || c == 'G' || c == 'T') {
            cnt++;
        } else {
            cnt = 0;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}
