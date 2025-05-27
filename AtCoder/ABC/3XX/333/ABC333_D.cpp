// 2024/04/01 18:56:58
// 2024/04/01 19:15:47 AC.
#include <iostream>
#include <vector>
#include <set>
#include <stack>
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
    vector<bool> done(N);
    done[0] = true;
    int max = 0;
    for (int tgt : G[0]) {
        stack<int> stk;
        int cnt = 0;
        stk.push(tgt);
        done[tgt] = true;
        cnt++;
        while (!stk.empty()) {
            int i = stk.top(); stk.pop();
            for (int next : G[i]) {
                if (!done[next]) {
                    stk.push(next);
                    done[next] = true;
                    cnt++;
                }
            }
        }
        if (max < cnt) {
            max = cnt;
        }
    }
    // cout << "max is " << max << endl; // debug
    cout << N - max << endl;
    return 0;
}
/*
1をルートにして、1の次数が1なら最初に消せばよいし
2以上ならつながっている頂点の数が少ないものから消していけば良い。
最も大きいものを残すと考える方が良いかしら。
同じか。(2024/04/01 19:02:09)
いずれにしても次数が1のときの例外処理は不要か。(2024/04/01 19:04:50)
*/
