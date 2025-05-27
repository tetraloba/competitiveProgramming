// 2023/05/14 13:55:10
// 
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }
    cout <<  << endl;
    return 0;
}
// 18C9 = 48,620 組み合わせ全探索で解けそう。 2023/05/14 13:57:52
// 組み合わせの列挙方法は？結局ライブラリゲーじゃね。 2023/05/14 14:03:25