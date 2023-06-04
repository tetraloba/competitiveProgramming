// 2023/06/04 16:12:16
// 2023/06/04 16:27:59 AC.
// 2023/06/04 16:40:37 WA.
// 2023/06/04 16:41:37 AC.
// 2023/06/04 16:44:12 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int K, S;
    cin >> K >> S;
    int ans = 0;
    for (int X = max(0, S - 2 * K); X <= min(S, K); X++) {
        ans += min(K, S - X) - max(0, S - X - K) + 1;
    }
    cout << ans << endl;
    return 0;
}