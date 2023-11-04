// 2023/11/04 15:58:28
// 2023/11/04 17:08:26 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int H, W;
    cin >> H >> W;
    vector<vector<char>> A(H, vector<char>(W)), B(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> B[i][j];
        }
    }

    for (int s = 0; s < H; s++) {
        for (int t = 0; t < W; t++) {
            if (A == B) {
                cout << "Yes" << endl;
                return 0;
            }
            vector<vector<char>> T(H, vector<char>(W));
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    T[i][(j + 1) % W] = A[i][j];
                }
            }
            A = T;
        }
        vector<vector<char>> T(H, vector<char>(W));
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                T[(i + 1) % H][j] = A[i][j];
            }
        }
        A = T;
    }
    cout << "No" << endl;
    return 0;
}
// 30*30 * 30*30 = 810000
// 全探索かなぁ・・・
