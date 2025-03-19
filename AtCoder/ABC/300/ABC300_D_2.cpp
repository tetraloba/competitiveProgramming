// 2025/03/19 15:09:51
// 2025/03/19 20:08:49 5WA
// 2025/03/19 20:37:51 AC.
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
vector<int> primes(int n) {
    vector<int> v;
    vector<bool> vb(n + 1, true);
    for (int i = 2; i <= n; i++) {
        if (vb[i]) {
            v.push_back(i);
        }
        int t = i * 2;
        while (t <= n) {
            vb[t] = false;
            t += i;
        }
    }
    return v;
}

int main(){
    long long N;
    cin >> N;
    int sqrtN = pow(N, 0.5) + 1;
    vector<int> ps = primes(sqrtN);
    // for (int i : ps) {
    //     cerr << i << ' ';
    // }
    // cerr << endl;

    int ans = 0;
    for (int ci = ps.size() - 1; 0 <= ci; ci--) {
        int b_max = min((long long)ps[ci], N / ps[ci] / ps[ci] / ps[0] / ps[0] + 1);
        int bi_max = lower_bound(ps.begin(), ps.end(), b_max) - ps.begin();
        for (int bi = bi_max - 1; 0 <= bi; bi--) {
            // cerr << ps[ci] << ' ' << ps[bi] << ' '; // debug
            long long a2_max = min((long long)ps[bi] * ps[bi], N / ps[ci] / ps[ci] / ps[bi] + 1);
            int a_max = pow(a2_max, 0.5);
            if ((long long)a_max * a_max < a2_max) {
                a_max += 1;
            }
            if (a_max <= 2) {
                // cerr << "no remain" << endl; // debug
                continue;
            }
            int ai_max = lower_bound(ps.begin(), ps.end(), a_max) - ps.begin();
            if (ai_max <= 0) {
                // cerr << "no a" << endl; // debug
                continue;
            }
            if (bi == ai_max) {
                int num = (1 + bi - 1 + 1) * (bi - 1 + 1) / 2;
                // cerr << "a free: " << num << endl; // debug
                ans += num;
                break;
            }
            int num = ai_max - 1 + 1;
            // cerr << "num: " << num << endl; // debug
            ans += num;
        }
    }
    cout << ans << endl;
    return 0;
}
/*
2,3,5,7,11,13,17,19,...
2,3,5 300
2,3,7 588
2,5,7 980
3,5,7 2205
2,3,11 1452
2,5,11 2420
3,5,11 5445
2,7,11 3388
3,7,11 7623
5,7,11 21175


2,3,X で Xは10^6以下
10^6以下の素数列を求めて・・・(2025/03/19 15:19:21)

素因数分解したほうが良いのか？(2025/03/19 18:38:32)
*/

