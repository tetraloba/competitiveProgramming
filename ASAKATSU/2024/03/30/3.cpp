// 2024/03/30 07:49:43
// 2024/03/30 08:22:26 11WA 2RE
// 2024/03/30 08:37:18 11WA
// 2024/03/30 09:16:09 AC.
#include <iostream>
#include <vector>
#include <map>
#define MOD 1000000007
using namespace std;
int main(){
    string chokudai = "chokudai";
    int num[256];
    num['c'] = 0;
    num['h'] = 1;
    num['o'] = 2;
    num['k'] = 3;
    num['u'] = 4;
    num['d'] = 5;
    num['a'] = 6;
    num['i'] = 7;

    string S;
    cin >> S;

    vector<long long> cnt[8];
    for (char c : chokudai) {
        cnt[num[c]] = vector<long long>(S.size());
    }
    if (S[0] == 'c') {
        cnt[0][0] = 1;
    }
    for (int i = 1; i < S.size(); i++) {
        bool flag = true;
        for (char c : chokudai) {
            cnt[num[c]][i] = cnt[num[c]][i - 1];
            if (S[i] == c) {
                flag = false;
            }
        }
        if (flag) {
            continue;
        }
        cnt[num[S[i]]][i] += S[i] == 'c' ? 1 : cnt[num[S[i]] - 1][i];
        cnt[num[S[i]]][i] %= MOD;
    }
    // /* debug */
    // for (auto c : cnt) {
    //     for (int i : c) {
    //         cout << i << ' ';
    //     }
    //     cout << endl;
    // }
    cout << cnt[7][S.size() - 1] << endl;
    return 0;
}
/*
各文字の数の累積和作って計算していけば…？(2024/03/30 07:51:39)
chokudaiに重複無し

2024/03/30 08:01:55
a:0 0 0 0 0 0 0 0 1 1 
c:1 1 2 2 2 2 2 2 2 2 
d:0 0 0 0 0 0 0 1 1 1 
h:0 1 1 2 2 2 2 2 2 2 
i:0 0 0 0 0 0 0 0 0 1 
k:0 0 0 0 0 1 1 1 1 1 
o:0 0 0 0 1 1 1 1 1 1 
u:0 0 0 0 0 0 1 1 1 1 
1 1 1 2 2 2 
2 0 1 1 3 3
3 0 0 0 0 3
4 0 0 0 0 0
5 0 0 0 0 0
6 0 0 0 0 0
7 0 0 0 0 0
8 0 0 0 0 0

 a b c a b c a b c
 1 1 1 2 2 2 3 3 3
 0 1 1 1 3 3 3 6 6
 0 0 1 1 1 4 4 4 10

*/
/*
Sを左から読んでいき、chokudaiの一部である文字(例えば`'d'`)が現れた時、その文字までの部分文字列(`"chokud"`)を作る方法の数は「その直前の文字までの`"chokud"`を作る方法の数 + 直前の文字までの`"choku"`を作る方法の数」である。8xNの配列で実装できる。
*/
