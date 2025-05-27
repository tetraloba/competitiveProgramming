// 2024/02/12 16:43:22
// 2024/02/12 17:12:31 AC.
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int H, W;
bool isInside(int i, int j) {
    return 0 <= i && i < H && 0 <= j && j < W;
}
int main(){
    int DIR8[8][2] = {{1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}};
    cin >> H >> W;
    vector<string> S(H);
    for (string &s : S) {
        cin >> s;
    }
    int ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') {
                ans++;
                stack<pair<int, int>> stk;
                stk.push(make_pair(i, j));
                S[i][j] = '.';
                while (stk.size()) {
                    pair<int, int> hw = stk.top();
                    stk.pop();
                    for (int k = 0; k < 8; k++) {
                        int h = hw.first + DIR8[k][0];
                        int w = hw.second + DIR8[k][1];
                        if (isInside(h, w) && S[h][w] == '#') {
                            stk.push(make_pair(h, w));
                            S[h][w] = '.';
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}