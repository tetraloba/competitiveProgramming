// 2024/12/02 16:21:57
// 2024/12/02 17:23:55 AC.
#include <iostream>
#include <vector>
#include <cmath>
#define LLMAX (numeric_limits<long long>::max())
using namespace std;
int main(){
    int V, E;
    cin >> V >> E;
    vector<vector<pair<int, int>>> G(V);
    for (int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        G[s].push_back({t, d});
    }

    int maxC = 1 << V;
    vector<vector<long long>> dp(maxC, vector<long long>(V, LLMAX));
    dp[1][0] = 0;
    for (int C = 0; C < maxC; C++) {
        // cerr << "C:" << C << endl; // debug
        for (int i = 0; i < V; i++) {
            if (dp[C][i] == LLMAX) {
                continue;
            }
            for (auto [next, weight] : G[i]) {
                if (C & (1 << next)) { // 既に通った頂点
                    continue;
                }
                int nextC = C;
                nextC |= (1 << next);
                dp[nextC][next] = min(dp[nextC][next], dp[C][i] + weight);
            }
        }
    }

    /* debug */
    // for (int C = 0; C < maxC; C++) {
    //     for (int i = 0; i < V; i++) {
    //         cerr << dp[C][i] << '\t';
    //     }
    //     cerr << endl;
    // }

    long long ans = LLMAX;
    for (int i = 0; i < V; i++) {
        if (dp[maxC - 1][i] == LLMAX) {
            continue;
        }
        for (auto [next, weight] : G[i]) {
            if (next != 0) {
                continue;
            }
            ans = min(ans, dp[maxC - 1][i] + weight);
        }
    }

    cout << (ans == LLMAX ? -1 : ans) << endl;
    return 0;
}
/*
集合Cの動かし方がqueueじゃなくても行けるのがよくわからないのだけれど。
あーなるほど、01100や00101などは必ず00100より後に来るから問題ないのか。(2024/12/02 17:30:15)
*/
