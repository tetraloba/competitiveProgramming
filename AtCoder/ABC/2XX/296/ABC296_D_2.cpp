// 2025/03/21 20:30:01
// 2025/03/21 21:18:33 6WA
// 2025/03/21 22:01:27 AC.
#include <iostream>
#include <vector>
using namespace std;
long long solve(long long N, long long M) {
    if (M <= N) {
        return M;
    }
    // if (N < M / N) {
    //     return -1;
    // }
    // if (N == M / N && M % N) {
    //     return -1;
    // }
    // if (M % N == 0) {
    //     return M;
    // }
    long long ans = INT64_MAX;
    for (long long O = M / N + (bool)(M % N); O <= M / O + (bool)(M % N); O++) {
        ans = min(ans, (M / O + (bool)(M % O)) * O);
    }
    return ans == INT64_MAX ? -1LL : ans;
}
int main() {
    long long N, M;
    cin >> N >> M;
    cout << solve(N, M) << endl;
    return 0;
}
/*
7 4
7,1
6,1
5,1
M < N なら Mか。

N < Mのみ考える (2025/03/21 20:35:20)
30 100
30, 4 +20
29, 4 +16
...
4, 25 +0

30 101
30,4 +19
29,4 +15
...
26,4 +3 ⭐️
25,5 +24
24,5 +19
23, +14
22, +9
21, +4 ⭐️
20,6 +19
...
17,6 +1 ⭐️
16,7 +11
15,7 +4
14,8 +11
13,8 +3
12,9 +7
11,10 +9
...

⭐️だけを見ていけばよいわけか。(2025/03/21 20:39:20)
11 99
11,10 +11
10,10 +1
だとまずいのか。
11,9 +0
が必須 (2025/03/21 20:43:35)
計算量はO(sqrt(M))か。(2025/03/21 20:58:44)
普通にi=1,2,...,sqrt(M)をやれば事足りるか。(2025/03/21 20:59:41)

4 7 -> 2~
4 13 -> 3~
*/
