// 2025/04/12 21:11:26
// 2025/04/12 22:24:14 10WA
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    for (int i = 0; i < N - 1; i++) {
        if (S[i] == 'o' && S[i + 1] == '?') {
            S[i + 1] = '.';
        }
    }
    for (int i = N - 1; 0 < i; i--) {
        if (S[i] == 'o' && S[i - 1] == '?') {
            S[i - 1] = '.';
        }
    }
    // cerr << S << endl; // debug

    vector<int> spaces; // ?の塊の集合
    int size = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '?') {
            size++;
        } else if (size) {
            spaces.push_back(size);
            size = 0;
        }
    }
    if (size) {
        spaces.push_back(size);
    }
    /* debug */
    // for (int i : spaces) {
    //     cerr << i << ' ';
    // }
    // cerr << endl;

    int cap_sum = 0; // spaces全体で詰められるoの最大数
    for (int i = 0; i < spaces.size(); i++) {
        cap_sum += (spaces[i] + 1) / 2;
    }
    // cerr << "cap_sum: " << cap_sum << endl; // debug

    int remainK = K; // spaces全体で詰めなければいけないoの数
    for (int i = 0; i < N; i++) {
        if (S[i] == 'o') {
            remainK--;
        }
    }
    // cerr << "remainK: " << remainK << endl; // debug

    bool fill = cap_sum <= remainK;
    // cerr << (fill ? "fill" : "no fill") << endl; // debug

    int space_i = 0;
    int i_in_space = 0;
    for (int i = 0; i < N; i++) {
        // cerr << "i: " << i << " -> "; // debug
        if (S[i] == '?') {
            if (fill && spaces[space_i] % 2) {
                S[i] = i_in_space % 2 ? '.' : 'o';
                // cerr << "fill" << endl; // debug
            } else {
                // cerr << "no fill" << endl; // debug
            }
            i_in_space++;
        } else if (i_in_space) {
            space_i++;
            i_in_space = 0;
            // cerr << "reset" << endl; // debug
        } else {
            // cerr << "skip" << endl; // debug
        }
    }

    cout << S << endl;
    return 0;
}
/*
oと.はそのままで、?が何になり得るかね。(2025/04/12 21:15:22)
o???
o.
.は連続しても良いのよね。.になり得ない場所って？ああ、K個の縛りか。(2025/04/12 21:16:36)
o.o.
o..o
01
10
連続するoになりえる場所だけピックアップするのか。
.o????o??.????o.
なら
.o.??.o.?.???.o.
だから2,1,3からK-3箇所選ぶ。
K-3=4ならば?? ? ?.?
K-3=3ならば?? ? ???
?
0
.
1
o

??
0
..
1
.o
o.

???
0
...
1
o..
.o.
..o
2
o.o

????
0
....
1
...o
..o.
.o..
o...
2
.o.o
o.o.

?5
0 -> .....
1 -> ?????
2
..o.o -> ?????
3
o.o.o -> o.o.o

?6
0 -> ......
1 -> ??????
2 -> ??????
3
o.o.o. -> ??????

?7
0 -> .......
1 -> ???????
2 -> ???????
3 -> ??????? K/2以下なら?Kか。0の時以外ね。(2025/04/12 21:43:59)
4 -> o.o.o.o
Kが奇数でK/2の時だけo.~.oになるわけか。

各塊について詰められるoの数を数え上げて、ある塊に少なくとも詰めなければいけない数を求めればよいと。(2025/04/12 21:46:36)
*/
/*
解説を読んで。
あーremainK=0ねえ。(2025/04/12 22:42:08)
*/
