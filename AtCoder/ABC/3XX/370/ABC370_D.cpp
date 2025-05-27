// 2025/03/27 09:19:37
// 2025/03/27 09:59:13 10WA
// 2025/03/27 10:25:44 AC.
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main(){
    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> walls_h(H), walls_w(W);
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            walls_h[h].insert(w);
            walls_w[w].insert(h);
        }
    }

    int ans = H * W;
    for (int q = 0; q < Q; q++) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        auto itr_r = walls_h[r].lower_bound(c);
        auto itr_c = walls_w[c].lower_bound(r);
        if (itr_r != walls_h[r].end() && *itr_r == c) {
            walls_h[r].erase(c);
            walls_w[c].erase(r);
            ans--;
        } else {
            if (itr_r != walls_h[r].begin()) {
                int left = *(prev(itr_r));
                walls_h[r].erase(left); // ボムの左側
                walls_w[left].erase(r); // 列側でも削除
                ans--;
            }
            if (itr_r != walls_h[r].end()) {
                int right = *(itr_r);
                walls_h[r].erase(right); // ボムの右側
                walls_w[right].erase(r); // 列側でも削除
                ans--;
            }
            if (itr_c != walls_w[c].begin()) {
                int top = *(prev(itr_c));
                walls_w[c].erase(top); // ボムの上側
                walls_h[top].erase(c); // 行側でも削除
                ans--;
            }
            if (itr_c != walls_w[c].end()) {
                int bottom = *(itr_c);
                walls_w[c].erase(bottom); // ボムの下側
                walls_h[bottom].erase(c); // 行側でも削除
                ans--;
            }
        }

        /* debug */
        // cerr << "-----" <<  endl;
        // for (int h = 0; h < H; h++) {
        //     cerr << walls_h[h].size() << ' ';
        // }
        // cerr << endl;
        // for (int w = 0; w < W; w++) {
        //     cerr << walls_w[w].size() << ' ';
        // }
        // cerr << endl;
        // for (int h = 0; h < H; h++) {
        //     for (int w = 0; w < W; w++) {
        //         cerr << (walls_h[h].count(w) ? '#' : '.');
        //     }
        //     cerr << endl;
        // }
        // cerr << r << ' ' << c << ' ' << ans << endl; // debug
    }
    cout << ans << endl;
    return 0;
}
/*
行と列は独立やねえ。(2025/03/27 09:20:44)
各行，各列の壁配列作ってニブタンで駄目なの？(2025/03/27 09:22:31)
いや～独立じゃないのか。行側で消えたら列側でも消す必要がある。でもこれもニブタンすれば行けるか…？(2025/03/27 09:24:57)
配列だと削除が重いのか。setだな。(2025/03/27 09:27:54)
setでlower_bound()できたっけ・・・?(2025/03/27 09:28:55)

####
####
0 1
#.##
####
0 1
...#
#.##
0 2
....
#..#

2 3 7
1 1
1 2
1 3
2 1
2 2
2 3
1 1
*/
