// 2023/10/31 21:25:09
// 2023/10/31 21:47:24 AC.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
long long int distance2(pair<int, int> a, pair<int, int> b){
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}
int main(){
    int N, D;
    cin >> N >> D;
    vector<pair<int, int>> pos(N);
    for (int i = 0; i < N; i++) {
        cin >> pos[i].first >> pos[i].second;
    }
    vector<bool> virus(N, false);
    virus[0] = true;
    queue<int> que;
    que.push(0);
    while (!que.empty()) {
        int tgt = que.front();
        que.pop();
        for (int i = 0; i < N; i++) {
            if (i == tgt) {
                continue;
            }
            if (distance2(pos[i], pos[tgt]) <= D * D) {
                if (!virus[i]) {
                    virus[i] = true;
                    que.push(i);
                }
            }
        }
    }
    for (int b : virus) {
        cout << (b ? "Yes" : "No") << endl;
    }
    return 0;
}
