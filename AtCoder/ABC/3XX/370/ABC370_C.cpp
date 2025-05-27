// 2024/11/25 10:22:56
// 2024/11/25 10:33:24 AC.
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    string S, T;
    cin >> S >> T;
    vector<string> ans;
    for (int i = 0; i < S.length(); i++) {
        if (T[i] < S[i]) {
            S[i] = T[i];
            ans.push_back(S);
        }
    }
    for (int i = S.length() - 1; 0 <= i; i--) {
        if (S[i] < T[i]) {
            S[i] = T[i];
            ans.push_back(S);
        }
    }
    cout << ans.size() << endl;
    for (string s : ans) {
        cout << s << endl;
    }
    return 0;
}
/*
要素数最小より、操作はSのTと異なる文字をTと一致させる操作に限られる。
問題は順番だけ。
左から、置き換えによって辞書順で早くなるもののみ置き換えていって、2周目で残りを置き換える？ (2024/11/25 10:27:55)
2週目は右からか・・・(2024/11/25 10:33:17)
*/
