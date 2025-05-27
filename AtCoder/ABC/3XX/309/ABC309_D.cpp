// 2024/07/07 08:17:57
// 2024/07/07 08:39:21 AC.
#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
/* グラフGにおいて、rootを根としたときの高さ(最大の深さ)を返す */
int height(vector<set<int>>& G, int root){
    int res = 0; // 最大の深さ
    /* BFS */
    vector<bool> done(G.size());
    queue<pair<int, int>> que; // 頂点番号, 深さ
    que.push({root, 0});
    done[root] = true;
    while (!que.empty()) {
        auto [v, depth] = que.front(); que.pop();
        for (int next : G[v]) {
            if (done[next]) {
                continue;
            }
            que.push({next, depth + 1});
            done[next] = true;
        }
        res = depth;
    }
    
    return res;
}

int main(){
    int N1, N2, M;
    cin >> N1 >> N2 >> M;
    vector<set<int>> G(N1 + N2);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].insert(b);
        G[b].insert(a);
    }

    /* 頂点1と頂点N1+n2それぞれからBFSして最も深い頂点を求める */
    cout << height(G, 0) + height(G, N1 + N2 - 1) + 1 << endl;
    return 0;
}
/*
なるほど、できるだけ離れるようにするのね。
頂点1と頂点N1+N2それぞれから幅優先探索して最後のやつ同士を繋ぐとか？(2024/07/07 08:23:01)
つまり木の高さを求めるって感じか。(2024/07/07 08:32:34)
*/

