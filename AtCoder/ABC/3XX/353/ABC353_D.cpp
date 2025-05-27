// 2024/07/09 20:49:24
// 2024/07/09 21:26:03 8WA
// 2024/07/09 21:32:48 6WA
// 2024/07/09 21:34:53 AC.
#include <iostream>
#include <vector>
#define NUM 998244353
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N), A_len(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        int cnt = 0, num = A[i];
        while (num) {
            num /= 10;
            cnt++;
        }
        A_len[i] = cnt;
    }

    vector<vector<int>> vv(N, vector<int>(11));
    for (int i = N - 2; 0 <= i; i--) {
        for (int j = 1; j <= 10; j++) {
            vv[i][j] = vv[i + 1][j] + (j == A_len[i + 1]);
        }
    }

    // /* debug */
    // for (int i = 0; i < N; i++) {
    //     for (int j = 1; j <= 10; j++) {
    //         cout << vv[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        /* A[i]がxとして使われる分 */
        long long n = 10;
        for (int j = 1; j <= 10; j++) {
            ans += (long long)A[i] % NUM * n % NUM * vv[i][j] % NUM;
            ans %= NUM;
            n = n * 10 % NUM;
        }
        /* A[i]がyとして使われる分 */
        ans += (long long)A[i] % NUM * i % NUM;
        ans %= NUM;
    }
    cout << ans << endl;
    return 0;
}
/*
f(x, y)はx * 10^k + yであり、kは1~10 (2024/07/09 20:53:27)
f(x, y) = f(y, x)とは限らないのよね。
こういう演算を指す言葉が有った気がするが数弱すぎて分からない(2024/07/09 20:56:00)
*/
