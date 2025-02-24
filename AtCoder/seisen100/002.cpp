// 2025/02/24 11:24:46
// 2025/02/24 11:27:19 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    int ans = 0;
    for (int i = 1; i <= N; i += 2) {
        int cnt = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) {
                cnt++;
            }
        }
        if (cnt == 8) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
