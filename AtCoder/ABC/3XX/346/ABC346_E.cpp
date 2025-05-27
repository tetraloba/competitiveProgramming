// 2024/04/05 11:45:35
// 2024/04/05 12:21:55 AC.
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
int main(){
    int H, W, M;
    cin >> H >> W >> M;
    vector<int> T(M), A(M), X(M);
    vector<pair<int, int>> color_r(H), color_c(W); // 色と更新時刻
    for (int i = 0; i < M; i++) {
        cin >> T[i] >> A[i] >> X[i];
    }
    map<int, long long> cnt; // 各色の数
    set<int> removed_r, removed_c; // 取り除かれた行と列
    int h = H, w = W; // 残りの行数と列数
    for (int i = M - 1; 0 <= i; i--) {
        if (T[i] == 1) {
            if (removed_r.count(A[i])) {
                continue;
            }
            cnt[X[i]] += w;
            removed_r.insert(A[i]);
            h--;
        } else {
            if (removed_c.count(A[i])) {
                continue;
            }
            cnt[X[i]] += h;
            removed_c.insert(A[i]);
            w--;
        }
        if (!h || !w) {
            break;
        }
    }
    if (h && w) {
        cnt[0] += (long long)h * w;
    }
    cout << cnt.size() << endl;
    for (auto [k, v] : cnt) {
        cout << k << ' ' << v << endl;
    }
    return 0;
}
/*
行と列それぞれについて各行(または列)の色と更新日時を記録しておけば良い。
いや、ケツから見ていって行や列を減らしていけばよいのか？(2024/04/05 11:50:42)
各行と列についてある時刻以降に更新されたものがいくつあるかを累積和または二分探索で求める？(2024/04/05 11:56:13)
232
130
130
やっぱりケツからやるほうが早そう。(2024/04/05 12:05:00)

*/
