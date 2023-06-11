// 2023/06/11 09:49:05
// 2023/06/11 11:06:52 RE.
// 2023/06/11 11:10:06 RE.
// 2023/06/11 11:12:37 AC.
#include <iostream>
#include <vector>
using namespace std;
bool inbox(int x, int y){
    if (0 <= x && x < 9 && 0 <= y && y < 9) {
        return true;
    }
    return false;
}
int main(){
    string S[9];
    for (int i = 0; i < 9; i++) {
        cin >> S[i];
    }
    int cnt = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (S[i][j] == '#') {
                for (int k = i; k < 9; k++) {
                    for (int l = j + 1; l < 9; l++) { // k,l どちらかだけ +1
                        if (S[k][l] == '#') {
                            int e[2];
                            if ((k - i + l - j) % 2 == 0 && ((l - j) - (k - i)) % 2 == 0) {
                                e[1] = (k - i + l - j) / 2;
                                e[0] = ((l - j) - (k - i)) / 2;
                                // cout << '(' << i << ',' << j << "),(" << k << ',' << l << ')' << endl; // debug
                                // cout << e[0] << ':' << e[1] << endl; // debug
                                // if (e[0] + e[1] != l - j) { // debug
                                //     cerr << "something wrong" << endl;
                                // }
                                if (inbox(i - e[0], j + e[1]) && inbox(k + e[0], l - e[1])) {
                                    if (S[i - e[0]][j + e[1]] == '#' && S[k + e[0]][l - e[1]] == '#') {
                                        // cout << "Here!" << endl; // debug
                                        cnt++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
// 対角線決めて(100 C 2)残りの場所にポーンがあるか判定すれば良い。 2023/06/11 09:53:52
// 2023/06/11 10:03:48
// e[0], e[1]としたとき
// v2 = v1[0] - e[0], v1[1] + e[1]
// v3 = v2[0] + e[1], v2[1] + e[0]
// v4 = v3[0] + e[0], v3[1] - e[1]
// v1 = v4[0] - e[1], v4[1] - e[0]

// すなわち、対角線
// v3 = v1[0] - e[0] + e[1], v1[1] + e[1] + e[0]
// v3[0] - v1[0] = -e[0] + e[1], v3[1] - v1[1] = e[1] + e[0]
// 

// ・・・・・・・・
// ・・・・・・・・
// ・・・・v2・・・
// ・・・・・・・・
// ・v1・・・・・・
// ・・・・・・v3・
// ・・・・・・・・
// ・・・v4・・・・
