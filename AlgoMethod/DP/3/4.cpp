// 2024/04/14 16:26:34
// 2024/04/14 16:45:20 WA
// 2024/04/14 17:00:17 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> W(N), V(N);
    for (int &w : W) cin >> w;
    for (int &v : V) cin >> v;

    vector<vector<int>> vv(N + 1, vector<int>(M + 1, -1));
    vv[0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= M; j++) {
            if (vv[i][j] == -1) {
                continue;
            }
            vv[i + 1][j] = max(vv[i + 1][j], vv[i][j]);
            if (j + W[i] <= M) {
                vv[i + 1][j + W[i]] = max(vv[i + 1][j + W[i]], vv[i][j] + V[i]);
            }
        }
    }
    cout << *max_element(vv[N].begin(), vv[N].end()) << endl;
    return 0;
}
