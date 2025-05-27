// 2024/04/07 08:24:21
// 2024/04/07 09:21:12 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void vprint(vector<int> v){
    for (int i : v) {
        cout << i << ' ';
    }
    cout << endl;
}
int main(){
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W)), B(A);
    for (auto &a : A) {
        for (int &i : a) {
            cin >> i;
        }
    }
    for (auto &b : B) {
        for (int &i : b) {
            cin >> i;
        }
    }
    // multiset<multiset<int>> msA, msB;
    // for (int i = 0; i < H; i++) {
    //     multiset<int> tmpA, tmpB;
    //     for (int j = 0; j < W; j++) {
    //         tmpA.insert(A[i][j]);
    //         tmpB.insert(B[i][j]);
    //     }
    //     msA.insert(tmpA);
    //     msB.insert(tmpB);
    // }
    // cout << (msA == msB ? "Yes" : "No") << endl;
    vector<int> seqH(H), seqW(W);
    for (int i = 0; i < H; i++) {
        seqH[i] = i;
    }
    for (int i = 0; i < W; i++) {
        seqW[i] = i;
    }
    int ans = INT32_MAX;
    do {
        do {
            bool diff = false;
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    if (A[seqH[i]][seqW[j]] != B[i][j]) {
                        diff = true;
                    }
                }
            }
            if (diff) {
                continue;
            }
            int cnt = 0;
            vector<int> seqH_copy = seqH, seqW_copy = seqW;
            for (int i = 0; i < H; i++) {
                for (int j = H - 1; i < j; j--) {
                    if (seqH_copy[j] < seqH_copy[j - 1]) {
                        swap(seqH_copy[j], seqH_copy[j - 1]);
                        cnt++;
                    }
                }
            }
            for (int i = 0; i < W; i++) {
                for (int j = W - 1; i < j; j--) {
                    if (seqW_copy[j] < seqW_copy[j - 1]) {
                        swap(seqW_copy[j], seqW_copy[j - 1]);
                        cnt++;
                    }
                }
            }
            if (cnt < ans) {
                ans = cnt;
            }
        } while (next_permutation(seqW.begin(), seqW.end()));
    } while (next_permutation(seqH.begin(), seqH.end()));
    
    if (ans == INT32_MAX) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}
/*
制約が極小さいので無理矢理でも解けそうだけれど・・・(2024/04/07 08:30:17)
一致させることが可能かどうか自体はmultisetのmultisetを比較することで判定可能。(2024/04/07 08:31:13)
↑DONE(2024/04/07 08:34:57)
いや、
0 1
0 1
0 1
1 0
がYesになってしまうから駄目か。
動かすというのは結局任意の並べ替えだから
5!*5!通りか。
120^2 普通に全探索でいけるくない・・・？(2024/04/07 08:41:13)
一致させる順列が見つかったとして、動かす回数はどうやって求める？
01234
34120
03412 5
01234 4

34120
31204 3
12304 2
41230 3
12340 3

231
うーん、普通にバブルソートするのが早いか。

2024/04/07  9:11
 1  2  3  4  5
 6  7  8  9 10
11 12 13 14 15
16 17 18 19 20

 1  3  2  5  4
11 13 12 15 14
 6  8  7 10  9
16 18 17 20 19

02143
0213

*/
