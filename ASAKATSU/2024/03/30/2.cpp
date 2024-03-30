// 2024/03/30 07:33:41
// 2024/03/30 07:49:56 AC.
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    int H, W;
    cin >> H >> W;
    vector<string> S(H), T(H);
    for (string &s : S) {
        cin >> s;
    }
    for (string &t : T) {
        cin >> t;
    }
    vector<string> Sv(W), Tv(W);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            Sv[j].push_back(S[i][j]);
            Tv[j].push_back(T[i][j]);
        }
    }
    map<string, int> Sm, Tm;
    for (string s : Sv) {
        Sm[s]++;
    }
    for (string t : Tv) {
        Tm[t]++;
    }
    auto Sitr = Sm.begin(), Titr = Tm.begin();
    while (Sitr != Sm.end() && Titr != Tm.end()) {
        // cout << (*Sitr).first << ' ' << (*Titr).first << endl; // debug
        if (*Sitr != *Titr) {
            cout << "No" << endl;
            return 0;
        }
        Sitr++;
        Titr++;
    }
    if (Sitr != Sm.end() || Titr != Tm.end()) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}
/*
縦のstringにしてsetで比較
いや重複時の数があるからmapか(2024/03/30 07:42:15)
*/
/*
列方向のstringにして各stringの数をmapで数え上げてmapの中身を比較した。
公式解説の「ソートして比較」という手法もあることを忘れないでおきたい。
*/
