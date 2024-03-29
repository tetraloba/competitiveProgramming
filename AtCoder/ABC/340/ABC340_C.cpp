// 2024/03/09 22:15:15
// 2024/03/09 22:57:45 AC.
#include <iostream>
using namespace std;
int main(){
    long long aa[2][2] = {{0, 1}, {0, 0}};
    long long N;
    cin >> N;
    aa[0][0] = N;

    long long ans = 0;
    while (2 <= aa[0][0] || 2 <= aa[1][0]) {
        long long bb[2][2] = {{0, 0}, {0, 0}};
        for (int i = 0; i < 2; i++) {
            if (aa[i][0] < 2) continue;
            ans += aa[i][0] * aa[i][1];
            if (aa[i][0] % 2) {
                bb[0][0] = aa[i][0] / 2;
                bb[1][0] = aa[i][0] / 2 + 1;
                bb[0][1] += aa[i][1];
                bb[1][1] += aa[i][1];
            } else {
                bb[i][0] = aa[i][0] / 2;
                bb[i][1] += aa[i][1] * 2;
            }
        }
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                aa[i][j] = bb[i][j];
            }
        }
    }
    cout << ans << endl;
    return 0;
}
/*
3
1 2
1 1 1

340
170 *2
85 *4
42 43 *4
21 *3 22
10 *3 11 *5
5 *8 6 *5

数字は高々2種類か。
シミュレーションしてO(log 10^17)ってところか。(2024/03/09 22:20:05)

入力例2 340 -> 2888 が合わない。

84 4
85 4

42 12
43 4

21 28
22 4

10 14
11 14

なるほどaa[i][0] % 2 == 0 の時、2で割った結果は(次世代の)小さい方とは限らないのか。
*/
/*
机上シミュレーションによって、幅優先探索的に(?)世代ごとに処理していった時に、同時に現れる数字は高々2種類であることが分かった。
この性質を利用して`aa[2][2] = {{小さい方の数字, ←の数}, {大きい方の数字, ←の数}}`という4種類の数字でシミュレーションすればO(log N)で解ける。
実装は「`+=`なのか`=`なのか」「2で割った後の数字が2種類の内小さい方なのか大きい方なのか」などで手間取った。
公式解説はメモ化再帰を使っており、恐らく深さ優先探索的な実装になっている。
僕は`N % 2`で場合分けしたが、なるほど`N / 2`と`(N + 1) / 2`で処理すれば場合分けは必要ないのか。
ユーザ解説はちょっと何言ってるのか分からない。(無能)

一応、一世代に数字が高々2種類しか存在しないことを証明しておこう。
ある世代での数字が1種類{A}であると仮定する。
    Aが偶数(2n)の時
        次世代 {A / 2, (A + 1) / 2} はそれぞれ
        {n, n} となり、{n}の1種類である。
    Aが奇数(2n - 1)の時
        次世代 {A / 2, (A + 1) / 2} はそれぞれ
        {n - 1, n} となり、{n - 1, n}の2種類である。
ある世代での数字が2種類{A - 1, A}であると仮定する。
    Aが偶数(2n)の時
        次世代 {(A - 1) / 2, ((A - 1) + 1) / 2, A / 2, (A + 1) / 2} はそれぞれ
        {n - 1, n, n, n} となり、{n - 1, n}の2種類である。
    Aが奇数(2n - 1)の時
        次世代 {(A - 1) / 2, ((A - 1) + 1) / 2, A / 2, (A + 1) / 2} はそれぞれ
        {n - 1, n - 1, n - 1, n} となり、{n - 1, n}の2種類である。
以上より、1種類の自然数Aから始まった時、各世代の数字は高々2種類である。
(Aやnの定義が雑だが良しとしよう。)

*/
