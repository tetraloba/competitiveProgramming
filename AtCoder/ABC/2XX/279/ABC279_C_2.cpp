//2023/05/14 10:01:32
//2023/05/14 10:16:44 WA.
//2023/05/14 10:27:04 AC. setじゃなくてmultisetだったわ…
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    int H, W;
    cin >> H >> W;

    vector<string> S(W);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char c;
            cin >> c;
            S[j] += c;
        }
    }
    vector<string> T(W);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char c;
            cin >> c;
            T[j] += c;
        }
    }

    multiset<string> stS, stT;
    for (int i = 0; i < W; i++) {
        stS.insert(S[i]);
    }
    for (int i = 0; i < W; i++) {
        stT.insert(T[i]);
    }

    // for (string str : stS) {
    //     cout << str << ' ';
    // }
    // cout << endl;

    cout << (stS == stT ? "Yes" : "No") << endl;
    return 0;
}