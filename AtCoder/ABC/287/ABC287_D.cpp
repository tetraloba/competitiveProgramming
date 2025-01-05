// 2025/01/05 20:45:43
// 2025/01/05 21:06:02 AC.
#include <iostream>
#include <vector>
using namespace std;
bool match_char(char c0, char c1) {
    return c0 == '?' || c1 == '?' || c0 == c1;
}
int main(){
    string S, T;
    cin >> S >> T;
    bool left_no = false;
    vector<int> right_no_count(T.size() + 1);
    for (int i = T.size() - 1; 0 <= i; i--) {
        if (match_char(S[i + S.size() - T.size()], T[i])) {
            right_no_count[i] = right_no_count[i + 1];
        } else {
            right_no_count[i] = right_no_count[i + 1] + 1;
        }
    }
    for (int x = 0; x <= T.size(); x++) {
        if (left_no) {
            cout << "No" << endl;
            continue;
        }
        cout << (right_no_count[x] ? "No" : "Yes") << endl;
        if (!match_char(S[x], T[x])) {
            left_no = true;
        }
    }
    return 0;
}
/*
変化するところだけやればよくない？
O(T + T)かな？(2025/01/05 20:48:26)
b?
a?c
?c
ac
a?
一回Noになったら永久にNoだよな？
サンプルケースがゴミ過ぎる。(暴言)

↑違うな。右が原因でNoなら解消される可能性はあるのか。
右のNo要因をケツから数え上げておいたほうが良いか？それが解消されるまではNo
左でNo要因が出た時点で以降全てNo (2025/01/05 20:52:43)
*/
/*
お、どうせWAかと思ったら一発AC.
index操作多めの問題で実装ミスなしとは素晴らしい。 (2025/01/05 21:06:55)
*/
