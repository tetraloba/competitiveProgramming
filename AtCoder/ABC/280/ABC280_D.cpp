// 2024/07/31 21:34:31
// 2024/07/31 22:06:43 26WA
// 2024/07/31 22:12:17 18WA
// 2024/07/31 22:19:53 AC.
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    long long K;
    cin >> K;

    map<long long, int> mp; // 素因数分解の結果
    for (long long i = 2; i * i <= K; i++) {
        if (K % i) {
            continue;
        }
        mp[i]++;
        K /= i;
        i--;
    }
    if (K > 1) {
        mp[K]++;
    }

    long long ans = 0;
    for (auto [k, v] : mp) {
        // cout << k << ':' << v << endl; // debug
        long long cand = 0;
        while (0 < v) {
            cand += k;
            long long tmp = cand;
            while (!(tmp % k)) {
                tmp /= k;
                v--;
            }
        }
        ans = max(ans, cand);
    }
    cout << ans << endl;
    return 0;
}
/*
N <= K (2024/07/31 21:35:29)
K <= 10^12 ってのは O(sqrt(K))は間に合うって話だわな。(2024/07/31 21:37:53)
2 4 6 8 10 12 14 16 18 20 22 24 26 28 30 32
1 2 1 3 1 2 1 4 1 2 1 3 1 2 1 5
*/
