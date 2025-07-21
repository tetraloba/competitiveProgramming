// 2025/07/21 20:58:13
// 2025/07/21 21:06:22 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> wall_protected(N + 1);
    vector<pair<int, int>> LR(M);
    for (auto &lr : LR) {
        cin >> lr.first >> lr.second;
        lr.first--;
        wall_protected[lr.first]++;
        wall_protected[lr.second]--;
    }
    for (int i = 1; i < N; i++) {
        wall_protected[i] += wall_protected[i - 1];
    }
    int ans = INT32_MAX;
    for (int i = 0; i < N; i++) {
        // cerr << wall_protected[i] << ' ';
        ans = min(ans, wall_protected[i]);
    }
    // cerr << endl;
    cout << ans << endl;
    return 0;
}
