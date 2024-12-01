// 2024/12/01 12:29:57
// 2024/12/01 12:55:30 TLE
// 2024/12/01 14:46:45 AC.
#include <iostream>
#include <vector>
using namespace std;
class Pos{
    public:
        int r;
        int c;
        Pos operator+(const Pos& other);
        Pos operator+(const int& num);
        Pos operator-(const Pos& other);
        Pos operator*(const int& num);
        void operator+=(const Pos& other);
        void operator-=(const Pos& other);
};
Pos Pos::operator+(const Pos& other){
    return {r + other.r, c + other.c};
}
Pos Pos::operator+(const int& num){
    return {r + num, c + num};
}
Pos Pos::operator-(const Pos& other){
    return {r - other.r, c - other.c};
}
Pos Pos::operator*(const int& num){
    return {r * num, c * num};
}
void Pos::operator+=(const Pos& other){
    this->r += other.r;
    this->c += other.c;
}
void Pos::operator-=(const Pos& other){
    this->r -= other.r;
    this->c -= other.c;
}

int pos_simu(){
    int N = 4;
    vector<vector<Pos>> A(N, vector<Pos>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = {i, j};
        }
    }
    vector<vector<Pos>> B(N, vector<Pos>(N));
    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i; j++) {
            for (int k = i; k < N - i; k++) {
                B[k][N - 1 - j] = A[j][k];
            }
        }
        A = B;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << '(' << A[i][j].r << ',' << A[i][j].c << ')';
        }
        cout << endl;
    }
    return 0;
}
int solve1(){ // O(N^3) TLE
    int N;
    cin >> N;
    vector<vector<char>> A(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    vector<vector<char>> B(N, vector<char>(N));
    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i; j++) {
            for (int k = i; k < N - i; k++) {
                B[k][N - 1 - j] = A[j][k];
            }
        }
        A = B;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << A[i][j];
        }
        cout << endl;
    }
    return 0;
}

/* 「始点は右上始まりで角を時計回りに移動、時計回りでy+,x+,y-,x-」を実装。O(N^2) */
int solve2(){
    /* input */
    int N;
    cin >> N;
    vector<vector<char>> A(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    /* process */
    // cerr << "process started!" << endl; // debug
    vector<vector<char>> B(N, vector<char>(N));
    Pos start_corners[4] = {{0, 1}, {1, 1}, {1, 0}, {0, 0}}; // 始点(右上始まりで角を時計回りに移動)
    Pos dir4[4] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // 時計回り
    Pos diff[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // y+,x+,y-,x-
    for (int i = 0; i < N / 2; i++) { // 外周からi番目を処理
        Pos tgt = start_corners[i % 4] * (N - 2 * i - 1) + i; // 処理対象点 (始点で初期化)
        Pos src = {i, i}; // tgtに対応するAの座標
        // cerr << i << "週目: " << tgt.r << ' ' << tgt.c << ' ' << src.r << ' ' << src.c << endl; // debug
        for (int j = 0; j < 4; j++) { // 4つの向きに動かす (一周)
            int d = (i + j) % 4;
            while (i <= tgt.r && tgt.r < N - i && i <= tgt.c && tgt.c < N - i) { // N - 2i 個進む
                // cerr << tgt.r << ' ' << tgt.c << ' ' << src.r << ' ' << src.c << endl; // debug
                B[tgt.r][tgt.c] = A[src.r][src.c];
                tgt += dir4[d];
                src += diff[j];
            }
            tgt -= dir4[d];
            src -= diff[j];
        }
    }

    /* output */
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cout << B[r][c];
        }
        cout << endl;
    }
    return 0;
}
int main(){
    solve2();
    return 0;
}
/*
サンプルでかいしさっぱり分からん。
4x4くらいのサンプルくれよ…

#..#
##..
..##
.##.

i=1
1,2,3,4
(1,1) (1,N)
(1,2) (2,N)
(1,3) (3,N)
(1,4) (4,N)
(2,1) (1,N-1)
(2,2) (2,N-1)
(2,3) (3,N-1)
...

i=2
2,3
(2,2) (2,N-1)
(2,3) (3,N-1)
(3,2) (2,N-2)
(3,3) (3,N-2)

愚直にやると計算量としては(N^2) + (N-2)^2 + (N-4)^2 + ... って感じか。
え、間に合わないの？分からんが？(2024/12/01 12:43:03)
一回、動きを理解しているかを確かめるために愚直にシミュレーションを書こう…(2024/12/01 12:43:29)
-> solve1()
シミュレーションはできた。O(N^3)になるわけね、なるほどね。(2024/12/01 12:56:55)
元の文字がどうだろうが、Nが決まれば、操作後にどの座標が元のどの座標になるかは一意に決まるはずなのよな。(2024/12/01 13:00:52)
元座標書き出してみるか…(2024/12/01 13:02:22)
-> pos_simu()

まあ、法則性はありそうだよね。(2024/12/01 13:05:54)
N=8
(7,0)(6,0)(5,0)(4,0)(3,0)(2,0)(1,0)(0#0)
(7,1)(6,6)(6,5)(6,4)(6,3)(6,2)(6,1)(0,1)
(7,2)(5,6)(2,5)(3,5)(4,5)(5,5)(5,1)(0,2)
(7,3)(4,6)(2,4)(3#3)(3,4)(5,4)(4,1)(0,3)
(7,4)(3,6)(2,3)(4,3)(4#4)(5,3)(3,1)(0,4)
(7,5)(2,6)(2#2)(3,2)(4,2)(5,2)(2,1)(0,5)
(7,6)(1,6)(1,5)(1,4)(1,3)(1,2)(1#1)(0,6)
(7,7)(6,7)(5,7)(4,7)(3,7)(2,7)(1,7)(0,7)
外周から
0#0 右上始まり 下y+ 左x+ 上y- 右x-
1#1 右下始まり 左y+ 上x+ 右y- 下x-
2#2 左下始まり 上y+ 右x+ 下y- 左x-
3#3 左上始まり 右y+ 下x+ 左y- 上x-
つまり、「始点は右上始まりで角を時計回りに移動、時計回りでy+,x+,y-,x-」か。

N=6
(5,0)(4,0)(3,0)(2,0)(1,0)(0#0)
(5,1)(4,4)(4,3)(4,2)(4,1)(0,1)
(5,2)(3,4)(2,3)(3#3)(3,1)(0,2)
(5,3)(2,4)(2#2)(3,2)(2,1)(0,3)
(5,4)(1,4)(1,3)(1,2)(1#1)(0,4)
(5,5)(4,5)(3,5)(2,5)(1,5)(0,5)
外周から
0#0 右上始まり 下y+ 左x+ 上y- 右x-
1#1 右下始まり
N=8と一緒か。

N=4
(3,0)(2,0)(1,0)(0#0)
(3,1)(2,2)(2,1)(0,1)
(3,2)(1,2)(1#1)(0,2)
(3,3)(2,3)(1,3)(0,3)
一緒だな。

じゃあこれを実装すれば一周で求まるのでO(N^2)か。(2024/12/01 13:20:28)
これx,yっていうよりr,cだよな。紛らわしい。

2024/12/01 14:41:49
{0, 1}, {1, 0}, {0, -1}, {-1, 0} のそれぞれについて
1をN - i - 1
0をi
に変換する計算式を考えたい。どうでも良いんだけど。
0, N - i - 1
i, N - 1
(N - 2i - 1) + i か。
*/
/*
多分後で見返しても意味分からないと思うが、
pos_simu()で出した↓の動きを無理やり実装したってことね。
(7,0)(6,0)(5,0)(4,0)(3,0)(2,0)(1,0)(0#0)
(7,1)(6,6)(6,5)(6,4)(6,3)(6,2)(6,1)(0,1)
(7,2)(5,6)(2,5)(3,5)(4,5)(5,5)(5,1)(0,2)
(7,3)(4,6)(2,4)(3#3)(3,4)(5,4)(4,1)(0,3)
(7,4)(3,6)(2,3)(4,3)(4#4)(5,3)(3,1)(0,4)
(7,5)(2,6)(2#2)(3,2)(4,2)(5,2)(2,1)(0,5)
(7,6)(1,6)(1,5)(1,4)(1,3)(1,2)(1#1)(0,6)
(7,7)(6,7)(5,7)(4,7)(3,7)(2,7)(1,7)(0,7)

解説のような美しい解析と一般化は僕には無理だ。
*/

