// 2024/03/03 18:13:18
// 2024/03/03 18:34:44 WA
// 2024/03/03 18:36:39 AC.
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int get_root(vector<int>& parent, int c){
    return parent[c] == c ? c : get_root(parent, parent[c]);
}
int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> VV(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        VV[u].push_back(v);
        VV[v].push_back(u);        
    }

    // /* debug */
    // for (vector<int> V : VV) {
    //     for (int v : V) {
    //         cout << v << ' ';
    //     }
    //     cout << endl;
    // }

    vector<int> parent(N);
    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }

    // /* debug */
    // for (int i : parent) {
    //     cout << i << ' ';
    // }
    // cout << endl;

    for (int i = 0; i < N; i++) {
        for (int &v : VV[i]) {
            int p_a = get_root(parent, i), p_b = get_root(parent, v);
            if (p_a != p_b) {
                parent[p_b] = p_a;
            }
        }
    }

    // /* debug */
    // for (int i : parent) {
    //     cout << i << ' ';
    // }
    // cout << endl;

    set<int> st;
    for (int i = 0; i < N; i++) {
        st.insert(get_root(parent, i));
    }
    cout << st.size() << endl;
    return 0;
}
/*
自分なりの理解でUnion-Findを実装してみた。
今後はライブラリ使っても良いかもね。
*/
