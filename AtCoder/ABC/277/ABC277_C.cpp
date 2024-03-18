// 2024/03/18 18:12:11
// 2024/03/18 18:21:24 AC.
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
using namespace std;
int main(){
    int N;
    cin >> N;
    map<int, set<int>> G;
    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        A--; B--;
        G[A].insert(B);
        G[B].insert(A);
    }
    map<int, bool> done;
    stack<int> stk;
    stk.push(0);
    done[0] = true;
    int ans = 0;
    while (!stk.empty()) {
        int tgt = stk.top(); stk.pop();
        if (ans < tgt) {
            ans = tgt;
        }
        for (int i : G[tgt]) {
            if (!done[i]) {
                stk.push(i);
                done[i] = true;
            }
        }
    }
    cout << ans + 1 << endl;
    return 0;
}
/*
グラフにして1階から到達できる最上階だね。(2024/03/18 18:13:48)
*/
