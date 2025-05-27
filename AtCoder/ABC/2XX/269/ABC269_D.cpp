// 2024/05/15 19:50:04
// 2024/05/15 20:07:46 AC.
#include <iostream>
#include <vector>
#include <stack>
#include <set>
using namespace std;
bool neighbor(pair<int, int> p1, pair<int, int> p2){
    if (p2.first == p1.first - 1) {
        if (p2.second == p1.second - 1 || p2.second == p1.second) {
            return true;
        }
        return false;
    }
    if (p2.first == p1.first) {
        if (p2.second == p1.second - 1 || p2.second == p1.second + 1) {
            return true;
        }
        return false;
    }
    if (p2.first == p1.first + 1) {
        if (p2.second == p1.second || p2.second == p1.second + 1) {
            return true;
        }
        return false;
    }
    return false;
}
int main(){
    int N;
    cin >> N;
    vector<pair<int, int>> XY(N);
    for (auto &xy : XY) {
        cin >> xy.first >> xy.second;
    }
    vector<set<int>> G(N);
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (neighbor(XY[i], XY[j])) {
                G[i].insert(j);
                G[j].insert(i);
            }
        }
    }
    int ans = 0;
    vector<bool> done(N);
    stack<int> stk;
    for (int i = 0; i < N; i++) {
        if (done[i]) {
            continue;
        }
        stk.push(i);
        done[i] = true;
        while (!stk.empty()) {
            int tgt = stk.top(); stk.pop();
            for (int next : G[tgt]) {
                if (done[next]) {
                    continue;
                }
                stk.push(next);
                done[next] = true;
            }
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}
