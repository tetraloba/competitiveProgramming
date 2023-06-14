// 2023/06/14 16:14:52
// 2023/06/14 17:16:37 AC.
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#define MOD 998244353
using namespace std;
int main(){
    long long N;
    cin >> N;
    long long T = N;
    long long ans = 0;
    int i = 1; // <= 18
    while (10 <= T) {
        long long num = 9 * (long long)pow(10, i - 1);
        // if (numeric_limits<long long>::max() / 9 < pow(10, i - 1)) {
        //     cerr << "over flow! in i=" << i << endl;
        // }
        if (num % 2) {
            ans += (1 + num) / 2 % MOD * (num % MOD) % MOD;
        } else {
            ans += (1 + num) % MOD * ((num / 2) % MOD) % MOD;
        }
        ans %= MOD;
        T /= 10;
        i++;
        // cerr << "ans is " << ans << " in i = " << i << endl;
    }
    // cerr << ans << endl;
    long long num = N - (long long)pow(10, i - 1) + 1;
    // if (num < 0) {
    //     cerr << "num < 0!" << endl;
    // }
    if (num % 2) {
        ans += (1 + num) / 2 % MOD * (num % MOD) % MOD;
    } else {
        ans += (1 + num) % MOD * ((num / 2) % MOD) % MOD;
    }
    cout << ans % MOD << endl;
    return 0;
}
// 1
// 1-9 (9)
// 2
// 10 - 99 (90)
// 3
// 100 -999 (900)

// 9 * 1 + 90 * 2 + 900 * 3 + ...
// 9 * 10^0 * 1 + 9 * 10^1 * 2 + 9 * 10^2 * 3