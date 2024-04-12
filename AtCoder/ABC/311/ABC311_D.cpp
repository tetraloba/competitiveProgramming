// 2024/04/12 20:04:44
// 2024/04/12 20:20:33 AC.
#include <iostream>
#include <vector>
#include <stack>
#include <set>
using namespace std;
const pair<int, int> DIR4[4] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
int main(){
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    for (string &s : S) {
        cin >> s;
    }
    vector<vector<bool>> touch(N, vector<bool>(M));
    set<pair<int, int>> done;
    stack<pair<int, int>> stk;
    stk.push({1, 1});
    done.insert({1, 1});
    touch[1][1] = true;
    while (!stk.empty()) {
        auto tgt = stk.top(); stk.pop();
        for (int d = 0; d < 4; d++) {
            auto pos = tgt;
            while (S[pos.first][pos.second] == '.') {
                touch[pos.first][pos.second] = true;
                pos.first += DIR4[d].first;
                pos.second += DIR4[d].second;
            }
            pos.first -= DIR4[d].first;
            pos.second -= DIR4[d].second;
            if (done.count({pos.first, pos.second})) {
                continue;
            }
            stk.push({pos.first, pos.second});
            done.insert({pos.first, pos.second});
        }
    }
    int ans = 0;
    for (auto v : touch) {
        for (bool b : v) {
            if (b) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
/*
200*200*4方向の160000通りなので全探索可能。
*/
