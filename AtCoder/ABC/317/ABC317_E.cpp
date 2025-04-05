// 2025/04/05 16:28:16
// 2025/04/05 17:12:39 AC.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/* A[p.firset][p.second]はEに含まれるか */
bool is_in(const int H, const int W, const vector<vector<char>>& A, const pair<int, int> p, const vector<char>& E) {
    const char c = A[p.first][p.second];
    for (char e : E) {
        if (c == e) {
            return true;
        }
    }
    return false;
}
bool can_entry(const int H, const int W, const vector<vector<char>>& A, const pair<int, int> p) {
    const vector<char> PASS = {'S', 'G', '.'};
    return is_in(H, W, A, p, PASS);
}
bool is_person(const int H, const int W, const vector<vector<char>>& A, const pair<int, int> p) {
    const vector<char> PERSON = {'>', 'v', '<', '^'};
    return is_in(H, W, A, p, PERSON);
}
bool can_see(const int H, const int W, const vector<vector<char>>& A, const pair<int, int> p) {
    const vector<char> OBJECT = {'#', '>', 'v', '<', '^'};
    return is_in(H, W, A, p, OBJECT);
}
int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> A(H + 2, vector<char>(W + 2, '#'));
    for (int h = 1; h <= H; h++) {
        for (int w = 1; w <= W; w++) {
            cin >> A[h][w];
        }
    }

    const pair<int, int> dir4[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (int h = 1; h <= H; h++) {
        for (int w = 1; w <= W; w++) {
            if (!is_person(H, W, A, {h, w})) {
                continue;
            }
            int th = h, tw = w;
            int d;
            switch (A[th][tw]) {
                case '>':
                    d = 0;
                    break;
                case 'v':
                    d = 1;
                    break;
                case '<':
                    d = 2;
                    break;
                case '^':
                    d = 3;
                    break;
            }
            while (true) {
                th += dir4[d].first;
                tw += dir4[d].second;
                if (can_see(H, W, A, {th, tw})) {
                    break;
                }
                A[th][tw] = '!';
            }
        }
    }
    /* debug */
    // for (int h = 0; h < H + 2; h++) {
    //     for (int w = 0; w < W + 2; w++) {
    //         cerr << A[h][w];
    //     }
    //     cerr << endl;
    // }

    /* find S */
    pair<int, int> spos; // start pos
    for (int h = 1; h <= H; h++) {
        for (int w = 1; w <= W; w++) {
            if (A[h][w] == 'S') {
                spos = {h, w};
            }
        }
    }
    /* BFS */
    vector<vector<bool>> done(H + 2, vector<bool>(W + 2));
    queue<pair<int, pair<int, int>>> que;
    que.push({0, spos});
    done[spos.first][spos.second] = true;
    while (!que.empty()) {
        auto [dist, tgt] = que.front(); que.pop();
        if (A[tgt.first][tgt.second] == 'G') {
            cout << dist << endl;
            return 0;
        }
        for (pair<int, int> d : dir4) {
            pair<int, int> next = {tgt.first + d.first, tgt.second + d.second};
            if (done[next.first][next.second]) {
                continue;
            }
            if (!can_entry(H, W, A, next)) {
                continue;
            }
            que.push({dist + 1, next});
            done[next.first][next.second] = true;
        }
    }
    cout << -1 << endl;
    return 0;
}
/*
人と視線を#に変換していくのでは間に合わないのか？(2025/04/05 16:32:09)
↑通路だけを置き換えていくならO(HW)だよなあ。(2025/04/05 16:33:02)
*/

