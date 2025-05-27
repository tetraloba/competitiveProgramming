// 2024/02/23 15:38:47
// 2024/02/23 16:08:53 AC.
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    if (N != M + 1) {
        cout << "No" << endl;
        return 0;
    }

    vector<set<int>> g(N, set<int>());
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].insert(v);
        g[v].insert(u);
    }

    // for debug
    // for (int i = 0; i < N; i++) {
    //     cout << i << ": ";
    //     for (int s: g[i]) {
    //         cout << s << ' ';
    //     }
    //     cout << endl;
    // }

    int edge = -1;
    for (int i = 0; i < N; i++) {
        if (g[i].size() == 1) {
            edge = i;
            break;
        }
    }
    if (edge == -1) {
        cout << "No" << endl;
        return 0;
    }

    int tgt_next = edge;
    for (int i = 0; i < M; i++) {
        int tgt = tgt_next;
        if (g[tgt].size() != 1) {
            cout << "No" << endl;
            return 0;
        }
        tgt_next = *g[tgt].begin();
        g[tgt].erase(tgt_next);
        g[tgt_next].erase(tgt);
    }
    cout << "Yes" << endl;
    return 0;
}