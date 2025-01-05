// 2025/01/05 09:17:04
// 2025/01/05 10:33:33 WA
// 2025/01/05 10:35:08 AC.
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
    long long N; // 4e12
    cin >> N;
    const int sqrtN = sqrt(N); // 2e6
    cerr << "sqrtN: " << sqrtN << endl;
    
    /* Sieve of Eratosthenes */
    vector<int> primes;
    vector<bool> sieve(sqrtN + 1, true);
    // sieve[0] = sieve[1] = false;
    primes.push_back(2);
    for (int i = 3; i <= sqrtN; i += 2) {
        if (!sieve[i]) {
            continue;
        }
        primes.push_back(i);
        int j = i * 2;
        while (j <= sqrtN) {
            sieve[j] = false;
            j += i;
        }
    }
    /* debug */
    // for (int prime : primes) {
    //     cerr << prime << ' ';
    // }
    // cerr << endl;

    /* O(sqrt(N)log(sqrt(N))) */
    int ans = 0;
    for (int i = 0; primes[i] * primes[i] < sqrtN; i++) {
        /* (2,3), (2,5), (2,7), (3,5)... */
        int pair_max = int(sqrtN / primes[i]) + 1;
        int pair_upper = lower_bound(primes.begin(), primes.end(), pair_max) - primes.begin();
        int num = pair_upper - 1 - i;
        // cerr << num << ' ';
        ans += num;

        /* (2,2,2,2), (3,3,3,3)... */
        long long prime = primes[i];
        if (prime * prime * prime * prime <= sqrtN) {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
/*
407073しかないなら全部求めておけばよくね() (2025/01/05 09:19:36)
約数奇数個だから平方数か。9個ってので平方根の条件が定まる？(2025/01/05 09:21:50)
6, 10, 14, 15
異なる素数の積かなあ…(2025/01/05 09:22:49)

225
1   3   5  9  15
225 75 45  25 

N <= 4e12
sqrt(N) <= 2e6
この範囲でエラトステネスの篩やって…て感じか。

2, 3, 5, 7, 11, 13
積がsqrt(N)以下になる組み合わせの数。ニブタンでO(NlogN)くらいで求まるか？(2025/01/05 09:31:35)

2,4,8,16
16*16 = 256
1 256
2 128
4 64
8 32
16
あーこのパターンもあるのかああ・・・・・・(2025/01/05 10:24:49)

6: 1,2,3,6
10: 1,2,5,10
14: 1,2,7,14
15: 1,3,5,15
16: 1,2,4,8,16
条件分からんぞ…
O(sqrtN sqrt(sqrtN))で良いか…？(´・ω・｀) (2025/01/05 10:27:53)
*/
/*
なんだろうな、この解けても楽しくない感じ。整数問題苦手かも(´・ω・｀)
*/
