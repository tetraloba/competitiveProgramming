// 2025/02/26 20:21:18
// 2025/02/26 20:40:21 AC.
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    int R;
    cin >> R;
    long long ans = 0;
    for (int i = 0; i < R; i++) {
        int j_max = pow((double)R * R - (i + 0.5) * (i + 0.5), 0.5) - 0.5;
        // cerr << j_max << endl; // debug
        ans += j_max;
    }
    ans = ans * 4 + 1;
    cout << ans << endl;
    return 0;
}
/*
1/4だけやれば良いのは分かるが・・・(2025/02/26 20:22:37)
頂点だけに注目すれば良いことを説明してくれているのは優しい。(2025/02/26 20:23:53)
各行について含まれる数をニブタンしてO(RlogR)，みたいなことなんだろうな。(2025/02/26 20:24:18)
x軸上を含み，y軸上を含まない第一象限を考える時，正方形の右上の頂点(i+0.5,j+0.5)だけキにすればよいか。(2025/02/26 20:29:30)
いやきちんと計算すればニブタン必要ないのか。(2025/02/26 20:32:35)
*/
