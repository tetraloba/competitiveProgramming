// 2025/05/27 12:39:33
// 2025/05/27 12:50:51 AC.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (string &s : S) {
        cin >> s;
    }
    
    queue<pair<int, int>> que;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (S[h][w] == 'E') {
                que.push({h, w});
            }
        }
    }
    /* BFS */
    pair<int, int> dir4[4] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    char arrow4[4] = {'^', '>', 'v', '<'}; // 逆向き
    while (!que.empty()) {
        auto tgt = que.front(); que.pop();
        for (int d = 0; d < 4; d++) {
            pair<int, int> next = {tgt.first + dir4[d].first, tgt.second + dir4[d].second};
            if (next.first < 0 || H <= next.first) {
                continue;
            }
            if (next.second < 0 || W <= next.second) {
                continue;
            }
            if (S[next.first][next.second] == '.') {
                S[next.first][next.second] = arrow4[d];
                que.push(next);
            }
        }
    }

    for (string s : S) {
        cout << s << endl;
    }
    return 0;
}
/*
まあ、EからのBFSだよね。(2025/05/27 12:41:10)
*/
