//2022/08/29 07:47:52
//2022/08/29 07:55:41 AC.
//ABC045_B - 3人でカードゲームイージー
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    string S[3];
    cin >> S[0] >> S[1] >> S[2];
    for (int i = 0; i < 3; i++) {
        reverse(S[i].begin(), S[i].end());
    }
    int t1 = 0;
    while (1) {
        if (!S[t1].size()) {
            cout << (char)('A' + t1) << endl;
            break;
        }
        int t2 = t1;
        t1 = *S[t1].rbegin() - 'a';
        S[t2].pop_back();
    }
    return 0;
}