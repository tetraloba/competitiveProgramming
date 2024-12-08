// ABC216_D - Pair of Balls
// 2024/12/09 07:56:18
// 2024/12/09 08:17:42 AC.
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> top(M, -1);
    vector<vector<int>> G(N); // 依存関係グラフ
    vector<int> ref(N); // 非参照数(被依存数)
    for (int i = 0; i < M; i++) {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            a--;
            if (top[i] != -1) {
                G[a].push_back(top[i]); // 依存関係
                ref[top[i]]++;
            }
            top[i] = a;
        }
    }
    
    /* debug */
    // for (int i = 0; i < N; i++) {
    //     cerr << i << "(" << ref[i] <<  ")" << ':';
    //     for (int a : G[i]) {
    //         cerr << a << ' ';
    //     }
    //     cerr << endl;
    // }

    stack<int> stk;
    for (int i = 0; i < N; i++) {
        if (ref[i]) {
            continue;
        }
        stk.push(i); // 被参照数0のものから処理する
    }
    while (!stk.empty()) {
        int tgt = stk.top(); stk.pop();
        for (int next : G[tgt]) {
            ref[next]--;
            if (ref[next]) {
                continue; // 被参照が残っている
            }
            stk.push(next);
        }
    }

    bool empty = true;
    for (int r : ref) {
        if (r) empty = false;
    }

    cout << (empty ? "Yes" : "No") << endl;
    return 0;
}
/*
グラフで解けたりする？(2024/12/09 08:00:12)
トポロジカル的な・・・
*/
