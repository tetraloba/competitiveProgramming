// 2025/03/29 10:16:08
// 2025/03/29 10:50:25 3TLE 3WA
// 2025/03/29 11:05:22 3WA
// 2025/03/29 11:18:44 AC.
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
using namespace std;
struct pos{
    int x;
    int y;
};
struct circle{
    pos p;
    int r;
};
int diff(int a, int b) {
    return a < b ? b - a : a - b;
}
long long dist2(pos p1, pos p2) { // 点p1, p2の距離の2乗
    long long dx = p1.x - p2.x;
    long long dx2 = dx * dx;
    long long dy = p1.y - p2.y;
    long long dy2 = dy * dy;
    return dx2 + dy2;
}
bool is_connected(circle c1, circle c2) {
    long long sr = c1.r + c2.r;
    long long sr2 = sr * sr;
    if (sr2 < dist2(c1.p, c2.p)) {
        return false;
    }
    long long dr = c1.r - c2.r;
    long long dr2 = dr * dr;
    if (dist2(c1.p, c2.p) < dr2) {
        return false;
    }
    return true;
}
string solve(int N, pos s, pos t, vector<circle> circles) {    
    int start = -1, goal = -1; // sに接する円とtに接する円。複数あってもその円同士は移動可能なので片方が分かれば十分。
    for (int i = 0; i < N; i++) {
        if (is_connected({s, 0}, circles[i])) {
            start = i;
        }
        if (is_connected({t, 0}, circles[i])) {
            goal = i;
        }
    }
    if (start == -1 || goal == -1) {
        return "No";
    }

    vector<vector<int>> G(N);
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (is_connected(circles[i], circles[j])) {
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
    }
    
    /* BFS */
    vector<bool> done(N);
    queue<int> que;
    que.push(start);
    while (!que.empty()) {
        int tgt = que.front(); que.pop();
        if (tgt == goal) {
            return "Yes";
        }
        for (int next : G[tgt]) {
            if (done[next]) {
                continue;
            }
            que.push(next);
            done[next] = true;
        }
    }
    return "No";
}
int main() {
    int N;
    cin >> N;
    pos s, t;
    cin >> s.x >> s.y >> t.x >> t.y;
    vector<circle> circles(N);
    for (circle &c : circles) {
        cin >> c.p.x >> c.p.y >> c.r;
    }
    cout << solve(N, s, t, circles) << endl;
    return 0;
}
/*
円と円が繋がっているかのグラフだね。(2025/03/29 10:16:42)
3000C2は間に合うのか(2025/03/29 10:18:35)
vector<set<int>> だと間に合わないのね。O(N^2 log N)とO(N^2)の差。(2025/03/29 11:06:24)
*/
