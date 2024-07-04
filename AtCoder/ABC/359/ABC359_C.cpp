// 2024/07/04 19:35:38
// 2024/07/04 20:05:29 3WA
// 2024/07/04 20:16:34 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    long long Sx, Sy, Tx, Ty;
    cin >> Sx >> Sy >> Tx >> Ty;

    /* (Sx,Sy)が(1,0)または(0,0)になるように調整 */
    long long pad_x = Sx - (Sx % 2 ^ abs(Sy) % 2), pad_y = Sy;
    Sx -= pad_x;
    Sy -= pad_y;
    Tx -= pad_x;
    Ty -= pad_y;
    // cout << Sx << ' ' << Sy << ' ' << Tx << ' ' << Ty << endl; // debug

    /* Ty動くコスト(cost_y)で(ついでに)移動できるxの範囲を求める */
    long long cost_y = abs(Ty);
    long long x_min = -cost_y, x_max = cost_y + 1;

    /* x方向のコスト(cost_x)を求める */
    long long cost_x = 0;
    if (Tx < x_min) {
        cost_x = (x_min - Tx + 1) / 2;
    } else if (x_max < Tx) {
        cost_x = (Tx - x_max + 1) / 2;
    }

    // cout << cost_x << ' ' << cost_y << endl; // debug
    cout << cost_x + cost_y << endl;
    return 0;
}
/*
制約が大きいので、計算で求められる問題だね。
とりあえず、上下方向の動きは確実に通行料1払う。
問題は左右方向。(2024/07/04 19:38:52)
Yの移動量がNだとしたら、そのNの通行料だけで行けるX座標は
N: X_min,X_max
0: 0,1
1: -1,2
2: -2,3
...
という感じに増えていく。
後は(端との差分)/2で求められそう？(2024/07/04 19:46:07)
Nが負だと
N: X_min,X_max
-1: -1,2
-2: 
...
あー同じか。(2024/07/04 19:47:03)
うわあ、スタート位置も可変かよ。調整面倒くさいな。(2024/07/04 19:48:01)
スタート位置が0,0または1,0になるように調整すればよいはず。(2024/07/04 19:48:58)
*/
