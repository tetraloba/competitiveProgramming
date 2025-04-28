// 2025/04/28 09:13:18
// 2025/04/28 09:28:55 22WA
// 2025/04/28 09:41:36 22TLE
// 2025/04/28 09:51:58 6TLE
// 2025/04/28 09:56:19 AC.
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main(){
    long long A, B;
    cin >> A >> B;
    set<int> divisor_primesA, divisor_primesB;
    divisor_primesA.insert(1), divisor_primesB.insert(1);
    for (int i = 2; (long long)i * i <= A; i++) {
        if (A % i) {
            continue;
        }
        while (A % i == 0) {
            A /= i;
        }
        divisor_primesA.insert(i);
    }
    divisor_primesA.insert(A);
    for (int i = 2; (long long)i * i <= B; i++) {
        if (B % i) {
            continue;
        }
        while (B % i == 0) {
            B /= i;
        }
        divisor_primesB.insert(i);
    }
    divisor_primesB.insert(B);

    set<int> common_divisor_primes;
    set_intersection(divisor_primesA.begin(), divisor_primesA.end(), divisor_primesB.begin(), divisor_primesB.end(), inserter(common_divisor_primes, common_divisor_primes.end()));
    cout << common_divisor_primes.size() << endl;
    return 0;
}
/*
どの異なる2つの整数についても互いに素とは？
4, 9みたいなのがあり得るって話？
でも4,9があるなら2,3もあるわけで、そっちを選べばよいよね。
6,35みたいな場合は2,3,5,7と選ぶほうがお得なわけで。結局素数では？(2025/04/28 09:22:58)
1は例外か。
サクッと素因数分解して共通の素数の数を数えるのではだめなのか？(2025/04/28 09:37:16)
あ、overflow...() (2025/04/28 09:41:03)
*/

