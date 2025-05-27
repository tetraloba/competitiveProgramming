// 2025/05/27 12:54:43
// 2025/05/27 13:03:58 AC.
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    int H, W, N;
    cin >> H >> W >> N;
    vector<set<int>> dust_r(H);
    vector<set<int>> dust_c(W);
    for (int i = 0; i < N; i++) {
        int h, w;
        cin >> h >> w;
        h--; w--;
        dust_r[h].insert(w);
        dust_c[w].insert(h);
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int query, param;
        cin >> query >> param;
        param--;
        if (query == 1) {
            cout << dust_r[param].size() << endl;
            for (int d_c : dust_r[param]) {
                dust_c[d_c].erase(param);
            }
            dust_r[param].clear();
        } else {
            cout << dust_c[param].size() << endl;
            for (int d_r : dust_c[param]) {
                dust_r[d_r].erase(param);
            }
            dust_c[param].clear();
        }
    }
    return 0;
}
