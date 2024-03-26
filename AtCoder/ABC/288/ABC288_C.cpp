// 2024/03/26 14:26:48
// 2024/03/26 14:52:22 WA
// 2024/03/26 14:57:30 AC.
#include <iostream>
#include <vector>
#include <set>
#include <stack>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<set<int>> G(N);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        G[--A].insert(--B);
        G[B].insert(A);
    }
    int ans = 0;
    vector<bool> done(N);
    auto itr = done.begin();
    while (itr != done.end()) {
        if (*itr) {
            itr++;
            continue;
        }
        stack<int> stk;
        stk.push(itr - done.begin());
        done[itr - done.begin()] = true;
        while (!stk.empty()) {
            int tgt = stk.top(); stk.pop();
            set<int> st(G[tgt]);
            for (int i : st) {
                if (done[i]) {
                    G[tgt].erase(i);
                    G[i].erase(tgt);
                    ans++;
                } else {
                    G[tgt].erase(i);
                    G[i].erase(tgt);
                    stk.push(i);
                    done[i] = true;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
