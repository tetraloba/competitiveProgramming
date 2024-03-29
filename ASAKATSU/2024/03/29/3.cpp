// 2024/03/29 07:49:06
// 2024/03/29 08:15:26 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    string S, T;
    cin >> S >> T;
    char A = 'A';
    char B = 'B';
    for (int i = 0; i < N; i++) {
        if (T[i] == A) {
            break;
        }
        if (S[i] == A && T[i] == B) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = N - 1; 0 <= i; i--) {
        if (T[i] == B) {
            break;
        }
        if (S[i] == B && T[i] == A) {
            cout << -1 << endl;
            return 0;
        }
    }
    int ans = 0;
    int A_cnt = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == A && T[i] == B) {
            if (A_cnt) {
                A_cnt--;
                ans++;
            } else {
                ans++;
            }
        } else if (S[i] == B && T[i] == A) {
            A_cnt++;
        }
    }
    ans += A_cnt;
    cout << ans << endl;
    return 0;
}
/*
BAABA
AABAB

AAABB
AABBB

変化させる位置にだけ興味がある？
A B A B

AAB
ABB は可能

AB
BB は不可能

変化させる位置にだけ興味を持つ時、左端がBであればそれより左にAが有れば可能

A A B 2
A B B 2
A A B B 2

変化の最初がBのとき
そのBより左にAが無ければ-1
Aがある時 ans += 変化の最初のAまでのBの数 // 不要か。
右端のAについても同様
A始まりB終わりの変化について
Aをstackに積んでいってBとペアで消せれば+1
残ったAまたはBは各々で+1

*/
