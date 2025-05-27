// 2024/02/24 20:04:57
// 2024/02/24 20:44:19 AC.
#include <iostream>
#include <vector>
#include <map>
#define MAX 200001
using namespace std;
int main(){
    int H, W, K;
    cin >> H >> W >> K;
    vector<string> S(H);
    for (string &s : S) {
        cin >> s;
    }
    int ans = MAX;
    /* 横 */
    if (K <= W) {
        for (int i = 0; i < H; i++) {
            map<char, int> cnt;
            cnt['x'] = 0; cnt['o'] = 0; cnt['.'] = 0;
            for (int r = 0; r < K - 1; r++) {
                cnt[S[i][r]]++;
            }
            for (int l = 0; l <= W - K; l++) {
                cnt[S[i][l + K - 1]]++;
                if (cnt['x'] == 0) {
                    ans = min(ans, cnt['.']);
                }
                cnt[S[i][l]]--;
            }
        }
    }
    /* 縦 */
    if (K <= H) {
        for (int j = 0; j < W; j++) {
            map<char, int> cnt;
            cnt['x'] = 0; cnt['o'] = 0; cnt['.'] = 0;
            for (int b = 0; b < K - 1; b++) {
                cnt[S[b][j]]++;
            }
            for (int t = 0; t <= H - K; t++) {
                cnt[S[t + K - 1][j]]++;
                if (cnt['x'] == 0) {
                    ans = min(ans, cnt['.']);
                }
                cnt[S[t][j]]--;
            }
        }
    }

    cout << (ans == MAX ? -1 : ans) << endl;
    return 0;
}