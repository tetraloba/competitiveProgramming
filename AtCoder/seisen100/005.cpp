// 2025/03/01 22:17:52
// 2025/03/01 22:26:20 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int ans = 0;
    if (A + B < C * 2) {
        ans += A * X + B * Y;
    } else {
        int m = min(X, Y);
        ans += C * 2 * m;
        X -= m;
        Y -= m;
        if (A < C * 2) {
            ans += A * X;
        } else {
            ans += C * 2 * X;
        }
        if (B < C * 2) {
            ans += B * Y;
        } else {
            ans += C * 2 * Y;
        }
    }
    cout << ans << endl;
    return 0;
}
