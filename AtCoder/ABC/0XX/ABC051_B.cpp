// 2023/06/04 16:12:16
// 2023/06/04 16:27:59 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int K, S;
    cin >> K >> S;
    int ans = 0;
    int MAX = min(S, K);
    for (int X = max(0, S - 2 * K); X <= MAX; X++) {
        for (int Y = max(0, S - X - K); Y <= MAX; Y++) {
            if (0 <= S - X - Y) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}