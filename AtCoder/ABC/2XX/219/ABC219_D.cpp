// 2024/04/27 19:12:55
// 2024/04/27 20:05:52 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, X, Y;
    cin >> N >> X >> Y;
    vector<vector<int>> vv(X + 1, vector<int>(Y + 1, INT32_MAX));
    vv[0][0] = 0;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        // cout << a << b << endl; // debug
        for (int x = X; 0 <= x; x--) {
            for (int y = Y; 0 <= y; y--) {
                if (vv[x][y] == INT32_MAX) {
                    continue;
                }
                int next_x = x + a, next_y = y + b;
                if (X < next_x) {
                    next_x = X;
                }
                if (Y < next_y) {
                    next_y = Y;
                }
                vv[next_x][next_y] = min(vv[next_x][next_y], vv[x][y] + 1);
            }
        }
        /* debug */
        // for (int x = 0; x <= X; x++) {
        //     for (int y = 0; y <= Y; y++) {
        //         cout.width(10);
        //         cout << vv[x][y] << ' ';
        //     }
        //     cout << endl;
        // }
    }
    cout << (vv[X][Y] == INT32_MAX ? -1 : vv[X][Y]) << endl;
    return 0;
}
/*
DP解けたああ！
*/
