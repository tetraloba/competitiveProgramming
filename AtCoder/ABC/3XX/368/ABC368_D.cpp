// 2024/11/26 18:17:37
// 2024/11/26 18:40:48 AC.
#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
vector<set<int>> G; // グラフ
int degree(int i){
    return G[i].size();
}
int main(){
    int N, K;
    cin >> N >> K;
    G = vector<set<int>>(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].insert(b);
        G[b].insert(a);
    }
    vector<bool> isV(N);
    for (int i = 0; i < K; i++) {
        int v;
        cin >> v;
        isV[--v] = true;
    }

    queue<int> que;
    for (int i = 0; i < N; i++) {
        if (G[i].size() == 1) {
            que.push(i);
        }
    }
    int ans = N;
    while (!que.empty()) {
        int tgt = que.front(); que.pop();
        // cerr << "tgt: " << tgt << endl; // debug
        if (isV[tgt]) {
            continue;
        }
        int next = *G[tgt].begin();
        G[next].erase(tgt);
        // cerr << "erased!" << endl;
        // G[tgt].erase(next); // 不要
        ans--;
        if (1 < G[next].size()) {
            continue;
        }
        que.push(next);
    }
    cout << ans << endl;
    return 0;
}
/*
葉から順に要らないやつを消していけば良い？(2024/11/26 18:22:39)
*/
