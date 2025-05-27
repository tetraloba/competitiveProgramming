// 2025/01/05 20:00:56
// 2025/01/05 20:24:46 AC.
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX (1e6)
using namespace std;
int main(){
    long long N;
    cin >> N;
    
    /* Sieve of Eratosthenes */
    vector<int> primes;
    vector<bool> sieve(MAX, true);
    primes.push_back(2);
    for (int i = 3; i < MAX; i += 2) {
        if (!sieve[i]) {
            continue;
        }
        primes.push_back(i);
        for (int j = i * 2; j < MAX; j += i) {
            sieve[j] = false;
        }
    }

    long long ans = 0;
    for (int prime : primes) {
        int q = prime;
        long long q3 = (long long)q * q * q;
        if (N <= q3) {
            break;
        }
        int p_max = min((long long)q, N / q3 + 1);
        int p_num = lower_bound(primes.begin(), primes.end(), p_max) - primes.begin();
        // cerr << q << ':' << p_num << endl;
        ans += p_num;
    }
    cout << ans << endl;
    return 0;
}
/*
q < 10^6
10^6未満の素数列を作っておいて、3 <= q < 10^6 を全探索？
中身はニブタンで良いからO(q log q)かな。
*/
