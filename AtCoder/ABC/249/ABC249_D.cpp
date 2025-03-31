// 2025/03/31 20:50:49
// 2025/03/31 21:18:05 2WA 4RE
// 2025/03/31 21:24:50 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }

    vector<int> cnt(*max_element(A.begin(), A.end()) + 1);
    for (int a : A) {
        cnt[a]++;
    }

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        long long cand = 0;
        for (int j = 1; j * j <= A[i]; j++) {
            if (A[i] % j) {
                continue;
            }
            if (A[i] / j == j) {
                cand += (long long)cnt[j] * cnt[j];
            } else {
                cand += (long long)cnt[j] * cnt[A[i] / j] * 2;
            }
        }
        // cerr << i << ' ' << cand << endl; // debug
        ans += cand;
    }
    cout << ans << endl;
    return 0;
}
/*
順番は関係ないのでソートできる。(2025/03/31 20:51:49)
Aj <= Ai
Ak <= Ai
Aiを素因数分解していくならO(N * N^0.5)で間に合うのか？(2025/03/31 20:59:23)

10
1 3 2 4 6 8  2  2 3 7
Ai 1 2 2 2 3 3  4  6 7 8
   1 6 6 6 4 4 11 14 2 8
*/
