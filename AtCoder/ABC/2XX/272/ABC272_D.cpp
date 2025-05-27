// 2023/06/16 00:40:14
// 2023/06/16 02:14:51 WA
// 2023/06/16 02:25:01 TLE
// 2023/06/16 02:46:24 WA 27/30
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
void printVV(vector<vector<int>>& vv){
    for (vector<int> v : vv) {
        for (int i : v) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return;
}
bool inMap(pair<int, int>& p, int N){
    if (0 <= p.first && p.first < N && 0 <= p.second && p.second < N) {
        return true;
    }
    return false;
}
pair<int, int> dir4[4] = {make_pair(1, 1), make_pair(1, -1), make_pair(-1, 1), make_pair(-1, -1)};
pair<int, int> move4(pair<int, int>& p, int dir){
    return make_pair(p.first * dir4[dir].first, p.second * dir4[dir].second);
}
int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> vv(N, vector<int>(N, -1));
    vv[0][0] = 0;
    if ((N - 1) * (N - 1) < M) {
        printVV(vv);
        return 0;
    }

    map<int, int> mp;
    for (int i = 0; i < N; i++) {
        mp[i * i] = i;
    }
    // pair<int, int> mv = make_pair(-1, -1);
    vector<pair<int, int>> mv;
    for (auto kv : mp) {
        if (mp.find(M - kv.first) != mp.end()) {
            mv.push_back(make_pair(kv.second, mp[M - kv.first]));
        }
    }
    // cerr << "mv is " << mv.first << ':' << mv.second << endl; // debug

    if (mv.size() == 0) {
        printVV(vv);
        return 0;
    }

    queue<pair<int, int>> que;
    que.push(make_pair(0, 0));
    while (!que.empty()) { // 幅優先探索？
        pair<int, int> p = que.front();
        que.pop();
        // cerr << p.first << ':' << p.second << endl; // debug
        for (int mv_i = 0; mv_i < mv.size(); mv_i++) {
            for (int dir = 0; dir < 4; dir++) {
                pair<int, int> move = move4(mv[mv_i], dir);
                pair<int, int> p_new = make_pair(p.first + move.first, p.second + move.second);
                // cerr << '(' << p_new.first << ':' << p_new.second << ')' << endl; // debug
                if (inMap(p_new, N) && (vv[p_new.first][p_new.second] == -1 || vv[p.first][p.second] + 1 < vv[p_new.first][p_new.second])) {
                    vv[p_new.first][p_new.second] = vv[p.first][p.second] + 1;
                    // vv[p_new.second][p_new.first] = vv[p.first][p.second] + 1;
                    que.push(make_pair(p_new.first, p_new.second));
                }
            }
        }
    }
    printVV(vv);
    return 0;
}
// 1, 4, 9, 16, 25, 36, 49, 64, ..., 1,000,000 (1000)
// 1 = 0 + 1
// 2 = 1 + 1
// 3 = None
// 4 = 0 + 4
// 5 = 1 + 4
// 6 = None
// 7 = None
// 8 = 4 + 4
// (400 - 1)^2 * 2 = 318,402 >= M <= 564^2 = 318,096