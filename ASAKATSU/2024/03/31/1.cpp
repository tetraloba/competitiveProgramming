// 2024/03/31 07:30:10
// 2024/03/31 07:47:22 AC.
// ARC136_A - A ↔ BB https://atcoder.jp/contests/arc136/tasks/arc136_a
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    int B_stk = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == 'C') {
            while (B_stk) {
                cout << 'B';
                B_stk--;
            }
            cout << 'C';
        }
        if (S[i] == 'A') {
            cout << 'A';
        }
        if (S[i] == 'B') {
            B_stk++;
            if (B_stk == 2) {
                cout << 'A';
                B_stk -= 2;
            }
        }
    }
    if (B_stk) {
        cout << 'B';
    }
    cout << endl;
    return 0;
}
/*
一旦全部のAをBBにした後、左からAに置き換えていくイメージ
BAはABにできる。(2024/03/31 07:33:27)

*/
