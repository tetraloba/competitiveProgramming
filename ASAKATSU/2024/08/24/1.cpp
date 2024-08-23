// 2024/08/24 07:30:06
// 2024/08/24 07:39:36 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (string &s : S) {
        cin >> s;
    }
    int ans = 0;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (S[h][w] == '#') {
                continue;
            }
            if (h < H - 1 && S[h + 1][w] == '.') {
                ans++;
            }
            if (w < W - 1 && S[h][w + 1] == '.') {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
