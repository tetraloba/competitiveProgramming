// 2023/10/11 19:51:43
// 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool inATCODER(char c){
    return c == 'a' || c == 't' || c == 'c' || c == 'o' || c == 'd' || c == 'e' || c == 'r';
}
int find(char c, string S){
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == c) {
            return i;
        }
    }
    return -1;
}
int main(){
    string S, T;
    cin >> S >> T;
    sort(S.rbegin(), S.rend());
    sort(T.rbegin(), T.rend());
    for (int i = 0; i < S.length(); i++) {
        int j = find(S[i], T);
        if (j != -1) {
            S[i] = '0';
            T[j] = '0';
        }
    }
    int cnt_at = 0, cnt_remain = 0;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] != '0') {
            cnt_remain++;
            if (S[i] == '@') {
                cnt_at++;
            } else if (!inATCODER(S[i])) {
                cout << "No" << endl;
                return 0;
            }
        }
        if (T[i] != '0') {
            cnt_remain++;
            if (T[i] == '@') {
                cnt_at++;
            } else if (!inATCODER(T[i])) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    // cout << S << endl;
    // cout << T << endl;
    cout << (cnt_remain / 2 <= cnt_at ? "Yes" : "No") << endl;
    return 0;
}
// @@a
// o@@
// c@@
// a@o
// 重複する文字(@を除く)を削除したあとに
// 半数以上が@ かつ atcoder に含まれていればOK?
