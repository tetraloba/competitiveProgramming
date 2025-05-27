// 2025/02/23 10:40:25
// 2025/02/23 10:53:35 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (string &s : S) {
        cin >> s;
    }

    /* 黒く塗りたい範囲 */
    int t = H - 1, b = 0, l = W - 1, r = 0;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (S[h][w] != '#') {
                continue;
            }
            t = min(t, h);
            b = max(b, h);
            l = min(l, w);
            r = max(r, w);
        }
    }

    // cerr << t << ' ' << b << ' ' << l << ' ' << r << endl; // debug

    /* 黒く塗りたい範囲に白マスが有ればfalse */
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (S[h][w] != '.') {
                continue;
            }
            if ((t <= h && h <= b) && (l <= w && w <= r)) {
                // cerr << h << ' ' << w << endl; // debug
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
/*
上下左右の一番でかいやつまでの範囲内に白マスが居なければ良いと。(2025/02/23 10:41:39)
*/
