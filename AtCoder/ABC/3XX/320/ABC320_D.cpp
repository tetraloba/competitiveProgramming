// 2024/03/17 20:21:53
// 2024/03/17 20:50:25 10WA overflow
// 2024/03/17 20:55:44 10WA 違ったかも
// 2024/03/17 21:16:16 AC.
#include <iostream>
#include <vector>
#include <set>
#include <stack>
#define POS_MAX INT64_MAX
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<set<pair<int, pair<int, int>>>> rel(N);
    for (int i = 0; i < M; i++) {
        int A, B, X, Y;
        cin >> A >> B >> X >> Y;
        A--; B--;
        rel[A].insert({B, {X, Y}});
        rel[B].insert({A, {-X, -Y}});
    }
    // /* debug */
    // for (int i = 0; i < M; i++) {
    //     for (auto r : rel[i]) {
    //         cout << i << ':' << r.first << '(' << r.second.first << ',' << r.second.second << ')' << endl;
    //     }
    // }
    vector<pair<long long, long long>> pos(N, {POS_MAX, POS_MAX});
    stack<int> stk;
    pos[0] = {0, 0};
    stk.push(0);
    while (!stk.empty()) {
        int tgt = stk.top(); stk.pop();
        for (auto t : rel[tgt]) {
            if (pos[t.first].first == POS_MAX) {
                pos[t.first] = {pos[tgt].first + t.second.first, pos[tgt].second + t.second.second};
                stk.push(t.first);
            }
        }
    }
    for (pair<long long, long long> p : pos) {
        if (p.first == POS_MAX) {
            cout << "undecidable" << endl;
        } else {
            cout << p.first << ' ' << p.second << endl;
        }
    }
    return 0;
}
/*
グラフ使うか…？
先に関係(相対座標)だけ取得して、
纏めて人1から絶対座標を計算すればO(N+M)にできるだろう。
常に人の値が小さい方から大きい方へのリンクになるようにしよう。

あー
1->3
2->3
が有った時に2が埋まらないか。
やっぱり根付き木作らないと駄目かなあ。(2024/03/17 21:05:50)
双方向グラフにして相対位置を双方向に計算できるようにすれば…
いや、接続だけ双方向にして相対位置は人番号が小さい方基準で統一すれば良いか。(2024/03/17 21:09:03)
*/
/*
互いの相対位置関係を単純双方向グラフ状に管理して、人1から深さ優先探索的に座標を確定していった。
*/
