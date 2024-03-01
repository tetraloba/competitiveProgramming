// 2024/03/01 18:19:35
// 2024/03/01 19:29:50 TLE
// 2024/03/01 20:58:37 AC
#include <iostream>
#include <vector>
#include <set>
#include <stack>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<multiset<int>> vs(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        vs[--u].insert(--v);
        vs[v].insert(u);
    }
    vector<int> blng_cmp(N); // 各頂点iの所属する連結成分の最小値
    for (int i = 0; i < N; i++) {
        blng_cmp[i] = i;
    }
    vector<bool> done(N); // スタックに積んだことがあればtrue (重複処理やループ対策)
    vector<int> vert_nums(N); // iが連結成分の最小値である時、その連結成分の頂点の数 (最小値でない時0)
    vector<int> edge_nums(N); // iが連結成分の最小値である時、その連結成分の辺の数の2倍
    for (int i = 0; i < N; i++) {
        if (blng_cmp[i] == i) {
            vert_nums[i] = 1;
            stack<int> stk;
            stk.push(i);
            done[i] = true;
            while (!stk.empty()) {
                int tgt = stk.top();
                stk.pop();
                for (int j : vs[tgt]) {
                    if (!done[j]) {
                        blng_cmp[j] = i;
                        vert_nums[i]++;
                        stk.push(j);
                        done[j] = true;
                    }
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        edge_nums[blng_cmp[i]] += vs[i].size();
    }

    // cout << "--debug--" << endl;
    // for (multiset<int> mst : vms) {
    //     cout << '{';
    //     for (int i : mst) {
    //         cout << i << ' ';
    //     }
    //     cout << '}';
    // }
    // cout << endl;
    // for (int i : blng_cmp) {
    //     cout << i << ' ';
    // }
    // cout << endl;
    // for (int i : vert_nums) {
    //     cout << i << ' ';
    // }
    // cout << endl;
    // for (int i : edge_nums) {
    //     cout << i << ' ';
    // }
    // cout << endl;

    for (int i = 0; i < N; i++) {
        if (vert_nums[i]) {
            // cout << vert_nums[i] << ' ' << edge_nums[i] << endl; // debug
            if (vert_nums[i] != edge_nums[i] / 2) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
