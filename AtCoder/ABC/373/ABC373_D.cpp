// 2024/11/27 15:02:03
// 2024/11/27 15:26:42 AC.
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#define UNDONE 1e18+1
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<map<int, int>> G(N);
    vector<long long> weights(N, UNDONE);
    for (int j = 0; j < M; j++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        G[u][v] = w;
        G[v][u] = -w; // ダミー辺
    }
    for (int i = 0; i < N; i++) {
        if (weights[i] != UNDONE) {
            continue;
        }
        weights[i] = 0;
        /* BFSで重みを確定していく (別にDFSでも良いが…) */
        queue<int> que;
        que.push(i);
        while (!que.empty()) {
            int tgt = que.front(); que.pop();
            for (auto [next, weight] : G[tgt]) {
                if (weights[next] != UNDONE) {
                    continue;
                }
                weights[next] = weights[tgt] + weight;
                que.push(next);
            }
        }
    }
    /* output */
    for (long long weight : weights) {
        cout << weight << ' ';
    }
    cout << endl;
    return 0;
}
/*
矛盾のないことが保証されているのだし、連結成分内で適当に決めて伝播させていけば良いだけでは？
向きも決まっているから組み合わせ爆発とかもないよね。(2024/11/27 15:11:04)
範囲的に、任意の点を0にして、10^18を超えてしまう可能性も無さそう…？
有向グラフをどうやって探索するかという問題は有るか？ダミー辺(重みで判定)をつけて疑似無向グラフみたいにするのはアリ？
制約5により双方向は有り得ない。
*/
/*
まあ、グラフ(Graph)の問題では有ったね。
*/
