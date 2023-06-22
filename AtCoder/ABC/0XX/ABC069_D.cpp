// 2023/06/22 21:25:58
// 2023/06/22 22:48:42 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int H, W, N;
    cin >> H >> W >> N;
    vector<int> color;
    for (int i = 1; i <= N; i++) {
        int tmp;
        cin >> tmp;
        for (int j = 0; j < tmp; j++) {
            color.push_back(i);
        }
    }

    // cerr << "color: ";
    // for (int i : color) {
    //     cerr << i << ' ';
    // }
    // cerr << endl;

    vector<vector<int>> ans(H, vector<int>(W, -1));
    int c = 0;
    bool leftToRight = true;
    for (int i = 0; i < H; i++) {
        if (leftToRight) {
            for (int j = 0; j < W; j++) {
                ans[i][j] = color[c++];
            }
        } else {
            for (int j = W - 1; 0 <= j; j--) {
                ans[i][j] = color[c++];
            }
        }
        leftToRight = !leftToRight;
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
// 必要ないけど
// 129
// 438
// 567
// の動きで実装するのむずくね…？