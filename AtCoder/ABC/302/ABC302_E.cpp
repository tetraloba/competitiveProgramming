// 2025/04/02 20:05:53
// 2025/04/02 21:12:07 TLE
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    int N, Q;
    cin >> N >> Q;
    vector<set<int>> G(N);
    int ans = N;
    for (int q = 0; q < Q; q++) {
        int opr;
        cin >> opr;
        int u, v;
        switch (opr)
        {
        case 1:
            cin >> u >> v;
            u--; v--;
            G[u].insert(v);
            G[v].insert(u);
            if (G[u].size() == 1) {
                ans--;
            }
            if (G[v].size() == 1) {
                ans--;
            }
            break;
        case 2:
            cin >> v;
            v--;
            for (int u : G[v]) {
                G[u].erase(v);
                if (G[u].size() == 0) {
                    ans++;
                }
            }
            if (G[v].size()) {
                ans++;
            }
            G[v].clear();
            break;
        }
        cout << ans << endl;
    }
    return 0;
}
/*
これって愚直にやって間に合わないの？(2025/04/02 21:05:30)
*/
