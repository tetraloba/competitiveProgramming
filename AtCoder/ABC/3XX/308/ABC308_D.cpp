// 2024/05/04 18:54:34
// 2024/05/04 19:09:51 TLE
// 2024/05/04 19:15:59 AC.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (auto &s : S) {
        cin >> s;
    }
    pair<int, int> DIR4[4] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    string snuke = "snuke";
    vector<vector<bool>> done(H, vector<bool>(W));
    queue<pair<pair<int, int>, int>> que;
    if (S[0][0] == snuke[0]) {
        que.push({{0, 1}, (0 + 1) % snuke.size()});
        que.push({{1, 0}, (0 + 1) % snuke.size()});
        done[0][0] = true;
    }
    while (!que.empty()) {
        auto [tgt, c] = que.front(); que.pop();
        // cout << tgt.first << ' ' << tgt.second << ' ' << c << endl; // debug
        // cout << snuke[c] << ' ' << S[tgt.first][tgt.second] << endl; // debug
        if (done[tgt.first][tgt.second]) {
            continue;
        }
        if (snuke[c] != S[tgt.first][tgt.second]) {
            continue;
        }
        if (tgt.first == H - 1 && tgt.second == W - 1) {
            cout << "Yes" << endl;
            return 0;
        }
        for (pair<int, int> d : DIR4) {
            pair<int, int> next = {{tgt.first + d.first}, {tgt.second + d.second}};
            if (next.first < 0 || H <= next.first || next.second < 0 || W <= next.second) {
                continue;
            }
            que.push({next, (c + 1) % snuke.size()});
        }
        done[tgt.first][tgt.second] = true;
    }
    cout << "No" << endl;
    return 0;
}
