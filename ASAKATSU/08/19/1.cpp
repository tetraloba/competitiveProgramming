//2022/08/19 07:30:08
//2022/08/19 07:42:11 AC.
//ABC211_B - Cycle Hit
#include <iostream>
#include <vector>
using namespace std;
int main(){
    string S[4];
    bool flg[4] = {false};
    cin >> S[0] >> S[1] >> S[2] >> S[3];
    for (int i = 0; i < 4; i++) {
        if (S[i].size() == 1) {
            flg[0] = true;
        } else if (S[i][0] == '2') {
            flg[1] = true;
        } else if (S[i][0] == '3') {
            flg[2] = true;
        } else {
            flg[3] = true;
        }
    }
    for (int i = 0; i < 4; i++) {
        // cout << i << ' ' << flg[i] << endl;
        if (!flg[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}