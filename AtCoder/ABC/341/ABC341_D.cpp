// 2024/03/10 18:41:00
// 2024/03/10 19:20:25 WA
// 2024/03/10 19:23:48 WA 積じゃなくてLCMか。
// 2024/03/10 19:53:07 AC.
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
using ULL=unsigned long long int;
int main(){
    int N, M;
    ULL K;
    cin >> N >> M >> K;
    ULL l = 0, r = __LONG_LONG_MAX__;
    while (l < r) {
        // ULL m = (l + r) / 2;
        ULL m = l / 2 + r / 2 + (l % 2 + 4 % 2) / 2;
        // cout << l << ' ' << m << ' ' << r << endl; // debug
        // ULL num = m / N + m / M - m / ((ULL) N * M) * 2;
        // ULL num = (m / N - m / ((ULL) N * M) * 2) + m / M;
        ULL num = (m / N - m / lcm((ULL)N, (ULL)M) * 2) + m / M;
        if (num < K) {
            l = m + 1;
        } else if (K < num) {
            r = m - 1;
        } else {
            r = m;
        }
    }
    cout << (l + r) / 2 << endl;
    return 0;
}
/*
X以下の自然数において NとMのいずれか一方でのみ割り切れる数の数は
X / N + X / M - X / (N * M)
Xを二分探索してそこから動かせば早いかな。
*/
/*
`LCM(N,M)`すべきところを`N*M`にしていて沼っていた。それにしてもoverflowするかどうかの判断が難しすぎるンゴ…
*/
