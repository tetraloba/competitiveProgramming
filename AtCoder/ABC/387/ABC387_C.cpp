// 2025/03/23 10:17:30
// 2025/03/23 12:02:40 7WA
// 2025/03/23 12:05:54 2WA
// 2025/03/23 12:18:50 AC.
#include <iostream>
#include <vector>
using namespace std;
vector<long long> digit2snake = {0, 0, 45, 330, 2355, 17688, 138513, 1116918, 9197343, 76928676, 651233661, 5565575586, 47929895211, 415358431344, 3618219192489, 31656022145934, 277980878525559, 2448687010535292, 21628005945912597}; // i桁のヘビ数の個数
// void tmp_digit2snake(){
//     long long ans = 0;
//     for (int i = 1; i < 18; i++) {
//         for (int j = 1; j <= 9; j++) {
//             long long tmp = 1;
//             for (int k = 1; k <= i; k++) {
//                 tmp *= j;
//             }
//             ans += tmp;
//         }
//         cerr << ans << ' ';
//     }
//     cerr << endl;
// }
long long snake(long long N) {
    if (N < 10) {
        return 0;
    }
    string strN = to_string(N);
    int head = strN[0] - '0';
    int wild_l = strN.size(); // 一番左の'?'
    for (int i = 1; i < strN.size(); i++) {
        if (wild_l == strN.size() && head <= strN[i] - '0') {
            wild_l = i;
        }
        if (wild_l != strN.size()) {
            strN[i] = '?';
        }
    }

    long long res = 0;
    long long tmp = 1;
    for (int i = wild_l; i < strN.size(); i++) {
        tmp *= head;
    }
    while (1 < wild_l) {
        res += tmp * (strN[wild_l - 1] - '0' + 1);
        // cerr << strN << ' ' << tmp * (strN[wild_l - 1] - '0' + 1) << endl; // debug
        tmp *= head;
        wild_l--;
        strN[wild_l] = '?';
        strN[wild_l - 1] = strN[wild_l - 1] - 1;
    }
    /* 最上位桁 */
    for (int i = strN[0] - '0'; 0 <= i; i--) {
        tmp = 1;
        for (int j = 0; j < strN.size() - 1; j++) {
            tmp *= i;
        }
        // cerr << "head " << tmp << endl; // debug
        res += tmp;
    }
    // cerr << "size(" << strN.size() - 1 << ") " << digit2snake[strN.size() - 1] << endl; // debug
    res += digit2snake[strN.size() - 1];
    // cerr << res << endl; // debug
    return res;
}
int main() {
    // tmp_digit2snake();
    long long L, R;
    cin >> L >> R;
    long long ans = 0;
    cout << snake(R) - snake(L - 1) << endl;
    return 0;
}
/*
難しいのか…？(2025/03/23 10:19:01)
10          1
20 .. 21    2
30 .. 32    3
..
90 .. 98    9
100         1
200 .. 211  4
300 .. 322  9
..
900 .. 988  81 (9^2)
1000        1 (1^3)
2000 .. 2111 4 (2^3)
問題は終端か。
0以上5920以下は何個かという場合
5920    0
591X    0
先頭より大きい物がある場合は・・・
5XXX    5^3
位置に依るか。
5290    0
52XX    5^2
51XX    5^2
50XX    5^2
YXXX    1^3+2^3+3^3+...5^3
5209    0
520X    5
51XX    5^2
50XX    5^2
2番目の桁をmin(先頭-1, 2番目-1)にしたところまでは計算可能？ (2025/03/23 10:34:13)

Nがヘビ数でないとき，先頭桁以上の桁のうち最も左のもの以右をX(先頭桁未満で自由)とすれば良い。
523749
523XXX
以左は
523XXX .. 520XXX: 5^3 * 4
51XXXX .. 50XXXX: 5^4 * 2
4XXXXX .. 1XXXXX: 4^5 + 3^5 + 2^5 + 1^5
XXXXX(5桁以下): 17688?
といったところか。

523442 .. 523440
52343X .. 52340X
5233XX .. 5230XX
522XXX .. 520XXX
51XXXX .. 50XXXX
4XXXXX .. 0XXXXX

97 -> 44
97 .. 90: 9^0 * 8 = 8
8X .. 1X: 8^1 + 7^1 + 6^1 + ... + 1^1 = 36
X: 0

210 -> 49
210: 2^0 = 1
20X: 2^1 = 2
1XX: 1^2 = 1
XX: 9^1 + 8^1 + 7^1 + ... 1^1 = 45;

1000 = 331
1000: 1
XXX: 9^2 + 8^2 + ... 1^2 + 45 = 330

9999 = 2355
9XXX .. 1XXX: 9^3 + 8^3 + 7^3 + ... 1^3 = 2025
XXX: 省略 = 330

合ってそう。後は実装だけ。(2025/03/23 10:55:10)

50372
503?? .. 500?? 5^2 * 4
5 -1 ??? .. 50??? 5^3 * 0;

50101 .. 50100: 2
500XX: 5^2 = 25
4XXXX .. 1XXXX
*/
/*
美しくないなあ…(2025/03/23 12:21:57)
*/
