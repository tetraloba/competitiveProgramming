// 2025/12/13 15:58:49
// 2025/12/13 16:25:00 AC.
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<set<int>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].insert(v);
        G[v].insert(u);
    }

    /* 01塗り分け全探索 */
    int C = 1 << N;
    int ans = INT32_MAX;
    for (int c = 0; c < C; c++) {
        vector<set<int>> grp(2);
        for (int i = 0; i < N; i++) {
            grp[(c >> i) & 1].insert(i);
        }
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            set<int> prod;
            set_intersection(G[i].begin(), G[i].end(), grp[(c >> i) & 1].begin(), grp[(c >> i) & 1].end(), inserter(prod, prod.end()));
            cnt += prod.size();
        }
        ans = min(ans, cnt / 2);
    }
    cout << ans << endl;
    return 0;
}
/*
2025/12/13 16:28:50
解説のほうが賢いなあ。辺側に注目するのかあ。
*/
