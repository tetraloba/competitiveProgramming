// 2024/03/08 23:04:10
// 2024/03/08 23:08:31 分からん。
// 2024/03/08 23:57:58 再開
// 2024/03/09 00:57:26 AC.
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    int N;
    cin >> N;
    long long ans = 0;
    for (int a = 1; a < N; a++) {
        int b = 1;
        while (true) {
            int cd = N - a * b;
            if (cd < 1) {
                break;
            }
            if (cd == 1) {
                ans += 1;
                break;
            }
            int c = 2, cnt = 2;
            while (true) {
                if (cd < c * c) {
                    break;
                }
                if (cd % c == 0) {
                    cnt += c == cd / c ? 1 : 2;
                }
                c++;
            }
            ans += cnt;
            b++;
            // cout << a << ' ' << b << ' ' << cnt << endl;
        }
    }
    cout << ans << endl;

    return 0;
}
