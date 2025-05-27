// 2025/01/06 09:50:21
// 2025/01/06 10:25:32 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
0,3,7,9
    1: 0 1
    2: 1 0
    3: -
    4: 0 2
    5: 1 1
*/
int range(vector<int>& walls, int index){
    if (index <= 0 || walls.back() <= index) {
        return -1; // error
    }
    int lb_idx = lower_bound(walls.begin(), walls.end(), index) - walls.begin();
    if (walls[lb_idx] == '#') {
        return 0; // 設置場所が壁
    }
    int left = index - walls[lb_idx - 1] - 1;
    int right = walls[lb_idx] - index - 1;
    return left + 1 + right;
}
int main(){
    int H, W;
    cin >> H >> W;
    vector<vector<char>> S(H + 2, vector<char>(W + 2, '#'));
    for (int h = 1; h <= H; h++) {
        for (int w = 1; w <= W; w++) {
            cin >> S[h][w];
        }
    }
    vector<vector<int>> walls_h(H + 2), walls_w(W + 2);
    for (int h = 0; h <= H + 1; h++) {
        for (int w = 0; w <= W + 1; w++) {
            if (S[h][w] == '#') {
                walls_h[h].push_back(w);
                walls_w[w].push_back(h);
            }
        }
    }
    /* debug */
    // for (int h = 0; h <= H + 1; h++) {
    //     cerr << "h " << h << ':';
    //     for (int i : walls_h[h]) {
    //         cerr << i << ' ';
    //     }
    //     cerr << endl;
    // }
    // for (int w = 0; w <= W + 1; w++) {
    //     cerr << "w " << w << ':';
    //     for (int i : walls_w[w]) {
    //         cerr << i << ' ';
    //     }
    //     cerr << endl;
    // }

    int ans = 0;
    for (int h = 1; h <= H; h++) {
        for (int w = 1; w <= W; w++) {
            if (S[h][w] != '.') {
                continue;
            }
            int num_h = range(walls_h[h], w);
            int num_w = range(walls_w[w], h);
            // cerr << h << ',' << w << ':' << num_h << ',' << num_w << endl; // debug
            ans = max(ans, num_h + num_w - 1);
        }
    }
    cout << ans << endl;
    return 0;
}
/*
上下と左右は独立して考えられるかしら。
各行、各列について障害物のindexを保持しておいて、ニブタンすればO(logH)で求められるか？
O(HW+(logH + logW))ってところかしら。(2025/01/06 09:54:07)

2,6
    0:0 1
    1:1 0
    2:-
    3:0 2
    4:1 1

流石に壁で囲ったほうが楽そうだな。
0,3,7,9
    1: 0 1
    2: 1 0
    3: -
    4: 0 2
    5: 1 1
*/
