// 2025/03/30 16:25:54
// 2025/03/30 16:54:52 AC.
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int root(int i, const vector<int>& parent) {
    int tgt = i;
    while (parent[tgt] != tgt) {
        tgt = parent[tgt];
    }
    return tgt;
}
int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> parent(N, -1);
    for (int i = 0; i < N; i++) {
        if (parent[i] != -1) {
            continue;
        }
        /* DFS */
        vector<int> stk;
        stk.push_back(i);
        while (stk.size()) {
            int tgt = stk.back(); stk.pop_back();
            parent[tgt] = i;
            for (int next : G[tgt]) {
                if (parent[next] != -1) {
                    continue;
                }
                stk.push_back(next);
            }
        }
    }
    /* debug */
    // for (int p : parent) {
    //     cerr << p << ' ';
    // }
    // cerr << endl;

    vector<set<int>> mine(N); // i(root)と繋いではいけない頂点(root)の集合
    int K;
    cin >> K;
    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        mine[root(x, parent)].insert(root(y, parent));
        mine[root(y, parent)].insert(root(x, parent));
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int p, q;
        cin >> p >> q;
        p--; q--;
        cout << (mine[root(p, parent)].count(root(q, parent)) ? "No" : "Yes") << endl;
    }
    return 0;
}
/*
union-findじゃないのかねえ(2025/03/30 16:28:17)
ああ，クエリはそれぞれ独立しているのね。辺を増やしていくのかと思ったよ(2025/03/30 16:49:20)
*/
/*
まあ，しっかりと想定解って感じやね。
*/
