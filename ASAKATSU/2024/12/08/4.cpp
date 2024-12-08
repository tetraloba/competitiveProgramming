// キーエンス プログラミング コンテスト 2020 B - Robot Arms
// 2024/12/08 07:42:29
// 2024/12/08 07:50:45 3に戻る
// 2024/12/08 07:59:49 再開
// 2024/12/08 08:35:52 WA
// 2024/12/08 09:10:55 WA
// 2024/12/08 09:33:15 だめだ、分からん。今度ゆっくり考えてくれ。
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
using Range = pair<int, int>;
int main(){
    int N;
    cin >> N;
    set<Range> ranges;
    for (int i = 0; i < N; i++) {
        int X, L;
        cin >> X >> L;
        ranges.insert({X - L + 1, X + L - 1});
    }
    int remove_count = 0;
    auto itr = ranges.begin(); // Lが小さいものから出してくれるはず
    Range most_right = *itr;
    itr++;
    while (itr != ranges.end()) {
        // cerr << itr->first << ',' << itr->second << ':'; // debug
        /* もし重複するなら、Rの大きい方を削除？ */
        if (itr->first <= most_right.second) { // 重複
            most_right = (most_right.second < itr->second ? most_right : *itr);
            // cerr << "dup!(" << most_right.first << ',' << most_right.second << ')' << endl; // debug
            remove_count++;
        } else {
            most_right = *itr;
            // cerr << "nodup" << endl; // debug
        }
        itr++;
    }
    cout << N - remove_count << endl;
    return 0;
}
/*
重複数が多いものから排除する貪欲で行ける？(2024/12/08 07:43:48)
LR範囲の問題と置き換えて良くて、平衡二分探索木(map)に詰めていけば、重複の多いところは求められる。(2024/12/08 07:46:44)
重複数-1は必ず取り除かなければならないけれど。(2024/12/08 07:47:27)
L順に並べて、Rの優先度付きキュー…いや違うか・・・(2024/12/08 07:48:27)
      ---
        ----
     --    ----
↑の実装やってみるか(2024/12/08 08:06:57)
あーそうか、同時に複数の重複が生まれる場合もあるのか。(2024/12/08 08:38:01)
----
 ------
  ---
重複が無くなるまで取り除く？
いや無いんだよ。2つめが追加された時点で取り除かれているはず。(2024/12/08 08:39:22)
Stackで良い気もしてきたなあ(2024/12/08 08:42:13)
Stackすら必要ないか。一番Rが大きいやつだけを保存しておけばよいか。(2024/12/08 08:43:13)
Lが小さい順に出した時、考えられるのは3通り
1 重複しない
---
   ---  
2 重複し、後者が大きい
---
 ---
3 重複し、前者が大きい
---
 -
または同値、か。同値の場合、Lが小さい方(範囲が大きい方)を消さなければいけないのか？どちらでも同じ気もするが
----
 ---
 (--)
L同値の場合も考えていないな
現在の実装だとRが小さい方からでてきて、Rが大きい方(あとから来たほう)が消されていく。別に問題ない気がするが。

*/
