// 2025/02/24 11:19:01
// 2025/02/24 11:24:23 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    while (true) {
        int n, x;
        cin >> n >> x;
        if (n == 0 && x == 0) {
            break;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                int k = x - i - j;
                if (j < k && k <= n) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
