// 2025/03/28 23:19:14
// 2025/03/28 23:29:14 21WA
// 2025/03/28 23:46:11 4WA
// 2025/03/29 00:30:02 AC.
#include <iostream>
#include <vector>
#include <map>
#include <random>
using namespace std;
long long solve(int N, long long K, vector<int> A) {
    vector<long long> cs(N + 1); // cumulative sum
    for (int i = 1; i <= N; i++) {
        cs[i] = cs[i - 1] + A[i - 1];
    }
    /* debug */
    // for (long long i : cs) {
    //     cerr << i << ' ';
    // }
    // cerr << endl;

    map<long long, int> mp;
    for (long long i : cs) {
        mp[i]++;
    }
    long long ans = 0;
    for (long long i : cs) {
        mp[i]--;
        ans += mp[i + K];
    }
    return ans;
}
// long long test(int N, long long K, vector<int> A) {
//     long long ans = 0;
//     for (int i = 0; i < N; i++) {
//         long long t = 0;
//         for (int j = i; j < N; j++) {
//             t += A[j];
//             if (t == K) {
//                 ans++;
//             }
//         }
//     }
//     return ans;
// }
int main() {
    int N;
    long long K;
    cin >> N >> K;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }

    // random_device seed_gen;
    // mt19937 engine(seed_gen());
    // uniform_int_distribution<int> dist(-5, 5);
    // for (int i = 0; i < 200; i++) {
    //     int N = 5, K = dist(engine);
    //     vector<int> A(N);
    //     for (int &a : A) {
    //         a = dist(engine);
    //     }
    //     if (solve(N, K, A) != test(N, K, A)) {
    //         cerr << N << ' ' << K << endl;
    //         for (int a : A) {
    //             cerr << a << ' ';
    //         }
    //         cerr << endl;
    //     }
    // }
    // cerr << endl;

    cout << solve(N, K, A) << endl;
    return 0;
}
/*
  8 -3  5  7  0 -4
0 8  5 10 17 17 13
0 5, 5 10, 8 13
累積和取って差がKになるやつをニブタンすれば良いのか。(2025/03/28 23:24:45)
mapで良いか(2025/03/28 23:24:53)

  13 -5 -3  5  7  0 -4 
0 13  8  5 10 17 17 13

6 0
  8 -3  5 -5  7  0 -4
0 8  5 10  5 12 12  8

6 1
  8 -3 -4  2 -2  0  0 8
0 8  5  1  3  1  1  1 9
  0 -3 -7  5 -7 -7 -7 1
     0 -4 -2 -4 -4 -4 4
        0  2  0  0  0 8
           0 -2 -2 -2 6
              0  0  0 8
                 0  0 8
                    0 8
                      0
*/
