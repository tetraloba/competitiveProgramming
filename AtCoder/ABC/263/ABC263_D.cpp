// 2025/03/26 21:52:07
// 2025/03/26 22:22:12 AC.
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;
int main(){
    int N, L, R;
    cin >> N >> L >> R;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }

    ll sum = 0;
    for (int a : A) {
        sum += a;
    }

    vector<ll> diff_l(N + 1), diff_r(N + 1);
    for (int i = 1; i <= N; i++) {
        diff_l[i] = diff_l[i - 1] + L - A[i - 1];
    }
    for (int i = N - 1; 0 <= i; i--) {
        diff_r[i] = diff_r[i + 1] + R - A[i];
    }
    /* debug */
    // for (int i : diff_l) {
    //     cerr << i << ' ';
    // }
    // cerr << endl;
    // for (int i : diff_r) {
    //     cerr << i << ' ';
    // }
    // cerr << endl;

    vector<pair<ll, int>> diff_r_idx(N + 1);
    for (int i = 0; i <= N; i++) {
        diff_r_idx[i] = {diff_r[i], i};
    }
    sort(diff_r_idx.begin(), diff_r_idx.end());

    queue<pair<ll, int>> que;
    for (auto e : diff_r_idx) {
        que.push(e);
    }

    long long ans = INT64_MAX;
    for (int i = 0; i <= N; i++) {
        while (que.front().second < i) {
            que.pop();
        }
        ans = min(ans, sum + diff_l[i] + que.front().first);
    }
    cout << ans << endl;
    return 0;
}
/*
    5  5  0  6  3
 0 -1 -2  2  0  1
   -4 -2  0 -3  0  0
y <= x のとき x <- y - 1 と同義なので x < y と仮定して良い(2025/03/26 21:56:22)
x < yの条件を満たす中で和が最小になる組み合わせを選ぶ(2025/03/26 22:02:02)

     9  -6  10  -1   2  10  -1   7  -15   5 = 20
0  -14 -13 -28 -32 -39 -54 -58 -70  -60 -70
   -50 -38 -41 -28 -26 -21 -8   -6    4  -8 0
-50, -55, -54, -56, -58, -60, -62, -66, -78, -68, -70

さて，正解はできるが，問題は計算量か。(2025/03/26 22:07:42)
昇順にソートして持っておけばよいか・・・(2025/03/26 22:08:41)
*/
/*
解説を読んで
ユーザ解説のDP実装思いつかなかったなあ。(2025/03/26 22:24:59)
*/
