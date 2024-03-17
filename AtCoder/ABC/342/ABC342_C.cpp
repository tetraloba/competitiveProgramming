// 2024/03/17 19:48:47
// 2024/03/17 20:06:23 AC.
#include <iostream>
#include <vector>
#define CHAR_MAX 26
using namespace std;
int main(){
    int N, Q;
    cin >> N;
    string S;
    cin >> S;
    cin >> Q;
    char replace[CHAR_MAX];
    for (int i = 0; i < CHAR_MAX; i++) {
        replace[i] = 'a' + i;
    }
    for (int i = 0; i < Q; i++) {
        char c, d;
        cin >> c >> d;
        for (int j = 0; j < CHAR_MAX; j++) {
            if (replace[j] == c) {
                replace[j] = d;
            }
        }
    }
    for (char s : S) {
        if (replace[s - 'a']) {
            cout << replace[s - 'a'];
        } else {
            cout << s;
        }
    }
    cout << endl;
    return 0;
}
/*
*/
/*
素直にシミュレーションするとO(NQ)で間に合わない。
各文字を最終的に何に置き換えるかが分かれば良いので、各文字(26種類)について変換先を保持する配列replace[]を用意する。
例えばreplace[3]='k'ならばdをkに置き換えることを意味する。
replace[0] = 'a', replace[1] = 'b'というように自身で初期化しておく。
全てのクエリについて、replace[]の値(置き換え先)がcである要素の値をdにする。O(26)/query
最後にreplace[]を使って実際に置き換えながら文字列Sを出力する。
以上でO(26*Q + N)で解ける。

より高速な解法は、「置き換え先から置き換え元を得られるようにする」という発想としては有ったが実装を思い付かず。。。
なるほど根付き木を使うのか。この前Union-Find実装したのだし、出来ても良かった。
*/
