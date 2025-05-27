// 2023/11/05 13:04:02
// 2023/11/05 15:48:50 2WA
// 2023/11/05 16:38:27 AC.
#include <iostream>
#include <vector>
using namespace std;
struct Sheet{
    vector<vector<char>> sheet;
    int H, W;
    int i_os, j_os; // offset, -9 ~ 10
    int top = -1, left = -1;
    int bottom, right;
};
char or_char(char A, char B) {
    return A == '#' || B == '#' ? '#' : '.';
}

int main(){
    vector<Sheet> S(3, {vector<vector<char>>(10, vector<char>(10, '.'))});
    
    for (int i = 0; i < 3; i++) {
        cin >> S[i].H >> S[i].W;
        for (int j = 0; j < S[i].H; j++) {
            for (int k = 0; k < S[i].W; k++) {
                cin >> S[i].sheet[j][k];
            }
        }
    }

    /* 各シートの黒の内 最上の行top と 最下の行bottom */
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < S[i].H; j++) {
            for (int k = 0; k < S[i].W; k++) {
                if (S[i].sheet[j][k] == '#') {
                    if (S[i].top == -1) {
                        S[i].top = j;
                    }
                    S[i].bottom = j;
                }
            }
        }
    }
    /* 各シートの黒の内 最左の列left と 最右の列right */
    for (int i = 0; i < 3; i++) {
        for (int k = 0; k < S[i].W; k++) {
            for (int j = 0; j < S[i].H; j++) {
                if (S[i].sheet[j][k] == '#') {
                    if (S[i].left == -1) {
                        S[i].left = k;
                    }
                    S[i].right = k;
                }
            }
        }
    }

    /* AやBの黒の 幅や高さが Xのそれよりも大きい場合 */
    if (S[2].bottom - S[2].top < S[0].bottom - S[0].top || S[2].right - S[2].left < S[0].right - S[0].left
     || S[2].bottom - S[2].top < S[1].bottom - S[1].top || S[2].right - S[2].left < S[1].right - S[1].left) {
        cout << "No" << endl;
        return 0;
    }

    for (int AB_reverse = 0; AB_reverse < 2; AB_reverse++) {

        /* AのtopがXのtop かつ AのleftがXのleft */
        S[0].i_os = S[0].top - S[2].top;
        S[0].j_os = S[0].left - S[2].left;
        // cout << endl;
        for (S[1].i_os = S[1].top; S[1].bottom - S[1].i_os <= S[2].bottom; S[1].i_os--) {
            for (S[1].j_os = S[1].left; S[1].right - S[1].j_os <= S[2].right; S[1].j_os--) {
                bool flag = true;
                for (int di = S[2].top; di <= S[2].bottom; di++) {
                    for (int dj = S[2].left; dj <= S[2].right; dj++) {
                        char A = 0 <= S[0].i_os + di && S[0].i_os + di < S[0].H && 0 <= S[0].j_os + dj && S[0].j_os + dj <= S[0].W ? S[0].sheet[S[0].i_os + di][S[0].j_os + dj] : '.';
                        char B = 0 <= S[1].i_os + di && S[1].i_os + di < S[1].H && 0 <= S[1].j_os + dj && S[1].j_os + dj <= S[1].W ? S[1].sheet[S[1].i_os + di][S[1].j_os + dj] : '.';
                        // cout << or_char(A, B);
                        // cout << A;
                        // cout << B;
                        if (or_char(A, B) != S[2].sheet[di][dj]) {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag) {
                        break;
                    }
                    // cout << endl;
                }
                if (flag) {
                    cout << "Yes" << endl;
                    return 0;
                }
                // cout << endl;
            }
        }

        /* AのtopがXのtop かつ BのleftがXのleft */
        S[0].i_os = S[0].top - S[2].top;
        S[1].j_os = S[1].left - S[2].left;
        // cout << endl;
        for (S[1].i_os = S[1].top; S[1].bottom - S[1].i_os <= S[2].bottom; S[1].i_os--) {
            for (S[0].j_os = S[0].left; S[0].right - S[0].j_os <= S[2].right; S[0].j_os--) {
                bool flag = true;
                for (int di = S[2].top; di <= S[2].bottom; di++) {
                    for (int dj = S[2].left; dj <= S[2].right; dj++) {
                        char A = 0 <= S[0].i_os + di && S[0].i_os + di < S[0].H && 0 <= S[0].j_os + dj && S[0].j_os + dj <= S[0].W ? S[0].sheet[S[0].i_os + di][S[0].j_os + dj] : '.';
                        char B = 0 <= S[1].i_os + di && S[1].i_os + di < S[1].H && 0 <= S[1].j_os + dj && S[1].j_os + dj <= S[1].W ? S[1].sheet[S[1].i_os + di][S[1].j_os + dj] : '.';
                        // cout << or_char(A, B);
                        // cout << A;
                        // cout << B;
                        if (or_char(A, B) != S[2].sheet[di][dj]) {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag) {
                        break;
                    }
                    // cout << endl;
                }
                if (flag) {
                    cout << "Yes" << endl;
                    return 0;
                }
                // cout << endl;
            }
        }

        Sheet T = S[0];
        S[0] = S[1];
        S[1] = T;
    }

    cout << "No" << endl;
    return 0;
}
// Xの最も左上の#がAかBか両方かを確かめる
// Aで決めた時、Aの左上で合わせて、Bとしてあり得るシートの条件(#,.,-)を決める
// Bも同様
// A,B両方の場合は1択検証するだけ
