// 2025/12/13 16:29:34
// 2025/12/13 17:21:02 7/27WA
// 2025/12/13 17:35:11 AC.
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N, A, B;
    string S;
    cin >> N >> A >> B >> S;
    
    vector<int> a_idxs, b_idxs; // i番目の'a'はS[a_idxs[i]]番目
    for (int i = 0; i < N; i++) {
        (S[i] == 'a' ? a_idxs : b_idxs).push_back(i);
    }
    while (a_idxs.size() < N) {
        a_idxs.push_back(N);
    }
    while (b_idxs.size() < N) {
        b_idxs.push_back(N);
    }
    
    long long ans = 0;
    int passed_a = 0, passed_b = 0; // lが通過した 'a' ('b')の数
    for (int l = 0; l < N - A + 1; l++) {
        int r_begin, r_end; // lに対して条件を満たすrの範囲は r_begin <= r < r_end
        r_begin = a_idxs[passed_a + A - 1];
        r_end = b_idxs[passed_b + B - 1];
        ans += max(0, r_end - r_begin);
        (S[l] == 'a' ? passed_a : passed_b)++;
        // cerr << r_begin << ' ' << r_end << endl; // debug
    }
    cout << ans << endl;
    return 0;
}
/*
2025/12/13 16:32:02
尺取法的なやつじゃないのか。
2025/12/13 16:34:39
再帰で書くチャレンジしようかしら。
2025/12/13 17:01:41
尺取法じゃないので普通に書く。
*/
/*
2025/12/13 17:38:02
解説を読んで。
累積和と二分探索によるO(N log N)解法と、尺取法でO(N)で解けることが説明されている。
僕の実装は前者の二分探索部分をidxs配列によりO(1)に高速化したO(N)解法かな。
尺取法ってのが分からんのよな。
2025/12/13 17:42:41
あーそうか、aの個数累積和に対して尺取法で、全てのlに対するr_beginをO(N)で求めることが可能か。
同様にbの個数累積和に対して尺取法で、全てのlに対するr_endをO(N)で求められる。
*/
