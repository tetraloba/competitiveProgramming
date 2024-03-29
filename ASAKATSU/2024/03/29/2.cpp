// 2024/03/29 07:32:48
// 2024/03/29 07:51:33 AC.
#include <iostream>
#include <vector>
using namespace std;
int H, W;
bool in_matrix(int i, int j){
    return 0 <= i && i < H && 0 <= j && j < W;
}
int main(){
    cin >> H >> W;
    vector<string> S(H);
    for (string &s : S) {
        cin >> s;
    }
    pair<int, int> dir8[8] = {{1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}};
    string snuke = "snuke";
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            for (int d = 0; d < 8; d++) {
                bool flag = true;
                for (int n = 0; n < 5; n++) {
                    int h = i + dir8[d].first * n;
                    int w = j + dir8[d].second * n;
                    if (!in_matrix(h, w)) {
                        flag = false;
                        break;
                    }
                    if (S[h][w] != snuke[n]) {
                        // cout << S[h][w] << ' ' << snuke[n] << endl; // debug
                        flag = false;
                    }
                }
                if (flag) {
                    for (int n = 0; n < 5; n++) {
                        cout << i + dir8[d].first * n + 1 << ' ' << j + dir8[d].second * n + 1 << endl;
                    }
                    return 0;
                }
            }
        }
    }
    return 0;
}
/*
100 x 100 x 8方向で間に合う
*/
