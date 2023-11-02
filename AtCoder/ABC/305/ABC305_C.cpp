// 2023/11/02 23:28:31
// 2023/11/02 23:42:29 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] != '#') {
                int cnt = 0;
                if (0 < i && S[i - 1][j] == '#') {
                    cnt++;
                }
                if (i < H - 1 && S[i + 1][j] == '#') {
                    cnt++;
                }
                if (0 < j && S[i][j - 1] == '#') {
                    cnt++;
                }
                if (j < W - 1 && S[i][j + 1] == '#') {
                    cnt++;
                }
                if (2 <= cnt) {
                    cout << i + 1 << ' ' << j + 1 << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}