// 2025/03/22 21:31:50
// 2025/03/22 22:14:51 11TLE 14WA
// 2025/03/22 22:21:46 AC.
#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<set<int>> G(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].insert(v);
        G[v].insert(u);
    }

    vector<vector<bool>> vv(N, vector<bool>(N)); // i j 間に辺が有るか
    vector<bool> odds(N); // 頂点iが根から見て奇数番目か
    /* BFS */
    queue<pair<int, bool>> que;
    que.push({0, false});
    while (!que.empty()) {
        auto [tgt, odd] = que.front(); que.pop();
        odds[tgt] = odd;
        for (int next : G[tgt]) {
            if (vv[tgt][next]) {
                continue;
            }
            vv[tgt][next] = true;
            vv[next][tgt] = true;
            que.push({next, !odd});
        }
    }

    set<pair<int, int>> possibles;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (vv[i][j]) {
                continue;
            }
            if (odds[i] == odds[j]) {
                continue;
            }
            possibles.insert({i, j});
        }
    }

    /* debug */
    for (auto p : possibles) {
        cerr << p.first << ' ' << p.second << '\t';
    }
    cerr << endl;

    bool myturn = possibles.size() % 2;
    cout << (myturn ? "First" : "Second") << endl;
    while (true) {
        pair<int, int> e;
        if (myturn) {
            if (possibles.size() == 0) {
                cout << -1 << ' ' << -1 << endl;
                break;
            }
            e = *possibles.begin();
            cout << e.first + 1 << ' ' << e.second + 1 << endl;
        } else {
            cin >> e.first >> e.second;
            if (e.first == -1) {
                break;
            }
            e.first--; e.second--;
        }
        possibles.erase(e);
        myturn = !myturn;
    }
    return 0;
}
/*
偶数と奇数って独立なのかしら…？(2025/03/22 21:46:05)
完全グラフ考えて，初期状態から繋げる場所と繋げない場所は決まる？順番(戦略)は関係ない？(2025/03/22 21:49:23)
初期状態によって引ける本数は変わりそう。(2025/03/22 21:52:46)
偶数閉路か奇数閉路かは，適当な根から偶奇振れば判定できるか。偶数同士や奇数同士なら奇閉路。(2025/03/22 21:55:02)

TLEってことは，まだ引けるのに引いてないってことか・・・(2025/03/22 22:17:23)
6
1 2
2 3
1 4
4 5
5 6

*/
