// 2024/12/07 14:42:29
// 2024/12/07 15:50:48 AC.
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
char invchar(char c){ // inverse char
    return isupper(c) ? tolower(c) : toupper(c);
}
int inversion_count(long long k){
    int invc = 0;
    while (k) {
        invc += k % 2;
        k /= 2;
    }
    return invc;
}
int main(){
    string S;
    cin >> S;
    int Q;
    cin >> Q;
    vector<long long> K(Q);
    for (long long &k : K) {
        cin >> k;
        k--;
    }
    for (long long k : K) {
        int n = k % S.size(); // 元の文字列のn文字目由来
        char c = S[n]; // 元の文字
        int r = inversion_count(k / S.size()); // 反転数
        if (r % 2) {
            c = invchar(c);
        }
        cout << c << ' ';
    }
    cout << endl;
    return 0;
}
/*
既存の文字は変わらないのね。長さは|S|*2^100
k番目の文字が何回目の処理で決定したかは
0011222233333333
log2(k)で求められる？
aB
aBAb
aBAbAbaB
aBAbAbaBAbaBaBAb
|S|になるまで2で剰余取って割っていって1だった回数ひっくり返せば良いのか。
あれだ、2進数で表した時の1の数、なんとか数だ。(2024/12/07 14:51:18)
popcountか。
ただそれだとlog2(|S|*2^100)でO(|S|)くらいになるから間に合わないのか。(2024/12/07 14:53:58)
Kは先読みできるから一度の探索で全部求めるのかなあ。(2024/12/07 14:55:02)
k番目の文字がSの何文字目由来かは、|S|で剰余を取ればO(1)か。
なら可能だな。K先読み使わないと間に合わない？とりあえず単純な実装にしてみよう。(2024/12/07 15:00:15)
000111222222333333333333
23番目は？
7...2 1 2 4 8
先に|S|で割る？よくわかんねえ。
(|S| * 2^100)
そうだな、log2(k / |S|)だな。境界値分からんけど。(2024/12/07 15:05:16)
1始まりなら12,13文字目 0始まりなら11,12文字目が境界 後者のほうが扱いやすそう
a B A b A b a B A b a B a B A b
a B a B A b A b a B a B a B a B 
int(log2(k))
- 0 1 1 2 2 2 2 3 3 3 3 3 3 3 3 4 4 4 4 ...
a B A b A b a B a B a B a B A b 
a B A b A b a B A b a B a B A b

|S| = 3
0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 k%10
0 0 0 1 1 1 2 2 2 3 3 3 4 4 4 5 5 5 6 6 6 7 7 7 8 8 8 k/3
- - - 0 0 0 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 2 2 3 3 3 log2(k/3)
0 0 0 1 1 1 2 2 2 2 2 2 3 3 3 3 3 3 3 3 3 3 3 3 4 4 4 ans

|S| = 2
0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 k(%10)
0 0 1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9 0 0 1 1 2 2 3 k/3(%10)
- - 0 0 1 1 1 1 2 2 2 2 2 2 2 2 3 3 3 3 3 3 3 3 3 3 3 log2(k/3)
0 0 1 1 2 2 2 2 3 3 3 3 3 3 3 3 4 4 4 4 4 4 4 4 4 4 4 ans
a B A b A b a B A b a B a B A b
a B A b a B a B A b A b A b A b あれれ・・・？

こっちだな。
0 0 1 1 1 1 2 2 1 1 2 2 2 2 3 3 1 1 2 2 2 2 3 3 2 2 3 3 3 3 4 4 inv (popcount)
0 0 1 1 1 1 0 0 1 1 0 0 0 0 1 1 1 1 0 0 0 0 1 1 0 0 1 1 1 1 0 0 inv%2
a B A b A b a B A b a B a B A b
a B A b A b a B A b a B a B A b 
とりあえず解けますよと。

*/
