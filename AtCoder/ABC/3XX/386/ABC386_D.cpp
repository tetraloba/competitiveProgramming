// 2025/02/28 07:57:34
// 2025/02/28 09:31:35 AC.
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
pair<int, int> maxB_minW(map<int, char>& squares) {
    int maxB = 0, minW = INT32_MAX;
    for (auto [i, color] : squares) {
        if (color == 'B') {
            maxB = max(maxB, i);
        } else {
            minW = min(minW, i);
        }
    }
    return {maxB, minW};
}
int main(){
    int N, M;
    cin >> N >> M;
    map<int, map<int, char>> x_squares, y_squares;
    for (int i = 0; i < M; i++) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        x_squares[x][y] = c;
        y_squares[y][x] = c;
    }

    bool ans = true;
    int minW_min = INT32_MAX;
    for (auto &[x, squares] : x_squares) {
        auto [maxB, minW] = maxB_minW(squares);
        ans &= maxB < minW;
        if (minW_min < maxB) {
            cerr << "minW_min < maxB! x" << x << ":maxB" << maxB << endl; // debug
            ans = false;
        }
        minW_min = min(minW_min, minW);
    }
    minW_min = INT32_MAX;
    for (auto &[y, squares] : y_squares) {
        auto [maxB, minW] = maxB_minW(squares);
        ans &= maxB < minW;
        if (minW_min < maxB) {
            cerr << "minW_min < maxB! y" << y << ":maxB" << maxB << endl; // debug
            ans = false;
        }
        minW_min = min(minW_min, minW);
    }
    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}
/*
左から，上から見たときにそれぞれ白→黒が出てこなければ良い(2025/02/28 08:01:06)
黒→白の変化点を考える。が，各行の変化点を扱うのは無理。(10^9行)
初手で塗られるマスは高々2*10^5なので，塗られた行・列だけ考えれば良い。(2025/02/28 08:03:03)
座標を圧縮？するか。
mapで独立させて管理すればよいのか・・・(2025/02/28 08:22:55)

2289 10
0 1 B
1 9 W
2 5 B
3 8 B
4 7 B
5 3 B
6 4 B
7 6 W
8 0 W
9 2 B


 0123456789
0 Bbbbbbbbb
1bbbbbbbbbW
2     Bbbbw
3       bBw
4       Bbw
5   B
6    B
7      W
8W
9wwB

各行で反転がないことと，変化点(lbw)が単調減少になる必要があるのか。(2025/02/28 09:00:07)
*/
/*
うーん，解説はもっとシンプルに解いているなあ…(2025/02/28 09:39:41)
*/
