// 2024/03/30 20:25:32
// 2024/03/30 20:37:23 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int W, B;
    cin >> W >> B;
    string piano = "wbwbwwbwbwbw";
    for (int start = 0; start < 12; start++) {
        int cnt_w = 0, cnt_b = 0;
        for (int i = start; i < W + B + start; i++) {
            if (piano[i % 12] == 'w') {
                cnt_w++;
            } else {
                cnt_b++;
            }
        }
        if (cnt_w == W && cnt_b == B) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
/*
bbは無い。
wwはある。
wwwはない。
B = W+1
B = W
B+1 = W
B+2 = W
まで。

92 66 がYes???(2024/03/30 20:29:56)
wbwbwwbwbwbwwbwbwwbwbwbwwbwb
あー。。。

スタート地点は12通り
212文字まで作れば全探索できる。
別に作らなくてもよいか。リングバッファで。(2024/03/30 20:34:07)
*/
