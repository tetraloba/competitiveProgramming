// 2025/02/26 20:01:17
// 2025/02/26 20:08:27 AC.
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    int ans = 0;
    vector<set<int>> G(N);
    for (int i = 0; i < M; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        v1--; v2--;
        if (v1 == v2) {
            ans++;
            continue;
        }
        if (G[v1].count(v2)) {
            ans++;
        }
        G[v1].insert(v2);
        G[v2].insert(v1);
    }
    cout << ans << endl;
    return 0;
}
