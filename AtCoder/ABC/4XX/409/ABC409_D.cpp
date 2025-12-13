// 2025/12/14 03:59:45
// 2025/12/14 04:30:09 8/19 WA
// 2025/12/14 04:38:47 8/19 WA
// 2025/12/14 05:56:47 AC.
#include <iostream>
#include <vector>
using namespace std;
// 文字列Sの部分文字列[l,r]を左に1巡回シフトした文字列を出力 (0-indexed)
void print_rotateSLR(string& S, int l, int r) {
    for (int i = 0; i < l; i++) {
        cout << S[i];
    }
    for (int i = l + 1; i <= r; i++) {
        cout << S[i];
    }
    cout << S[l];
    for (int i = r + 1; i < S.size(); i++) {
        cout << S[i];
    }
    cout << endl;
}
void solve1(int N, string S) {
    int l = 0, r = 0;
    for (int i = 0; i < N - 1; i++) {
        if (S[i] <= S[i + 1]) {
            continue;
        }
        l = i;
        for (r = i + 1; r < N - 1; r++) {
            if (S[l] < S[r + 1]) {
                break;
            }
        }
        break;
    }
    cerr << S << ' ' << l << ' ' << r << ':'; // debug
    print_rotateSLR(S, l, r);
}
void solve2(int N, string S) {
    vector<bool> r_min_update(N);
    char r_min = INT8_MAX;
    for (int i = N - 1; 0 <= i; i--) {
        if (S[i] < r_min) {
            r_min = S[i];
            r_min_update[i] = true;
        }
    }
    int l = 0;
    while (l < N - 1 && r_min_update[l]) {
        l++; // r_min_update[N-1] == true なので l = 0 or l < N - 1
    }
    if (l == N - 1) {
        // 既に辞書順最小
        print_rotateSLR(S, 0, 0);
        return;
    }
    int r = l;
    if (l + 1 < N && r_min_update[l + 1]) {
        // min(S[r]) となる r (l < r) は r = l + 1 で自動的にlの位置に来るのでS[l]をどこまで右に動かすべきかを考える。
        while (r < N - 1 && S[r] <= S[l]) {
            r++;
        }
    } else {
        // min(S[r]) となる r (l < r) を探索
        while (!r_min_update[r]) {
            r++;
        }
    }
    cerr << S << ' ' << l << ' ' << r << ':';
    print_rotateSLR(S, l, r);
}
void solve3(int N, string S) {
    int l = 0, r = 0;
    while (l < N - 1 && S[l] <= S[l + 1]) {
        l++;
    }
    r = l;
    while (r < N - 1 && S[r + 1] <= S[l]) {
        r++;
    }
    // cerr << S << ' ' << l << ' ' << r << ':'; // debug
    print_rotateSLR(S, l, r);
}
int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N; string S;
        cin >> N >> S;
        solve3(N, S);
    }
    return 0;
}
/*
2025/12/14 04:41:35
そうか、cbaみたいに最後に一番小さいやつがある場合に駄目なのか。
2025/12/14 04:42:42
とにかく一番小さいやつを先頭に持ってくるっていう考え方のはず。
2025/12/14 04:44:17
既に一番小さいやつが先頭にあるならば、先頭を除いた中で同じことを繰り返す…という再帰が一番愚直なO(N^2)実装か。
どうせ模範解答はO(N)実装だろう。
2025/12/14 04:47:23
大小関係が反転している場所を見つけて、そこから最小までを入れ替えるのが正解？
違うな。
2 4 3 1 だと 2 1 4 3 よりも 1 2 4 3 が嬉しい。
2025/12/14 04:50:12
ケツから最小値探索して更新された位置に注目？
1 2 4 3
o o x o
1 7 2 5 3 4 6
o x o x o o o
2025/12/14 04:53:21
いや、
1 5 3 7 -> 1 3 5 7
o x o o
1 7 3 5 -> 1 3 7 5
o x o o
いいのか・・・？
一番左のxから、それ以降で最初のoまでをrotateする？
2025/12/14 04:56:08
違うんだよなあ。
1 7 2 5 3 4 6
o x o x o o o
1 2 5 3 4 6 7
2025/12/14 04:57:03
とりあえず、最左のx以降の最左のoをxの位置に持ってくるべきってことは間違いなさそう？
2025/12/14 04:59:18
そのやり方として、xをlにする方法(xoが隣接している場合)とoをrにする方法の2通りが考えられるのよな。
そんなややこしい話かねえ。
1 4 5 2 6 3
o x x o x o
2025/12/14 05:05:13
xをlにするのは共通で、xoが隣接していないならばoをrにする、隣接しているならば？
2025/12/14 05:46:50
ん？違うな。巡回シフトしても任意の文字は先頭に持ってこれないわ。全く頭が働いていないな。
cbaならbacが解のはず。acbにはできない。
*/
/*
2025/12/14 06:04:38
solve3()で正答したが、solve1()のデバッグを行う。
1 5 acbcb で
1 4 abcbc とすべきところを
1 2 abccb となるから駄目なのか。
if (S[l] <= S[r + 1]) break; で同じなら止めるのではなく、同じなら動かし続けなければいけないのか。
2025/12/14 06:07:47
solve1()でもAC.
*/
