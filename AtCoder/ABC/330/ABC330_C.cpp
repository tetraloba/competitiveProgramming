// 2024/02/20 13:24:37
// 2024/02/20 13:36:11 WA
// 2024/02/20 13:40:00 AC.
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main(){
    long long D;
    cin >> D;
    int max_x = (int) pow(D, 0.5);
    long long ans = D;
    for (int x = 0; x <= max_x; x++) {
        int y = (int) pow(abs(D - (long long) x * x), 0.5);
        for (int tmp_y = y - 1; tmp_y <= y + 1; tmp_y++) {
            int tmp_min = abs((long long) x * x + (long long) tmp_y * tmp_y - D);
            ans = tmp_min < ans ? tmp_min : ans;
        }
    }
    cout << ans << endl;
    return 0;
}
// x^2 + y^2 が 最もDに近くなる時
// 0 <= x <= (10^12)^0.5 を全探索…？
