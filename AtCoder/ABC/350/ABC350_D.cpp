// 2024/07/09 15:32:01
// 2024/07/09 15:59:17 19WA 1TLE
// 2024/07/09 16:36:59 AC.
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<set<int>> G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].insert(b);
        G[b].insert(a);
    }

    vector<int> parents(N, -1);
    for (int i = 0; i < N; i++) {
        set<int> st;
        st.insert(i);
        for (int p : G[i]) {
            int next = parents[p];
            while (next != -1) {
                p = next;
                next = parents[p];
                // cout << "loop test 1" << endl; // debug
            }
            st.insert(p);
            // cout << "loop test 2" << endl; // debug
        }
        if (!st.size()) {
            continue;
        }
        auto itr = st.begin();
        int root = *itr;
        itr++;
        while (itr != st.end()) {
            parents[*itr] = root;
            // cout << "loop test 3" << endl; // debug
            itr++;
        }
        // cout << "loop test 4" << endl; // debug
    }

    vector<int> roots(N, -1);
    for (int i = 0; i < N; i++) {
        int p = i, next = parents[p];
        while (next != -1) {
            p = next;
            next = parents[p];
        }
        roots[i] = p;
    }

    map<int, int> mp;
    for (int r : roots) {
        mp[r]++;
    }
    long long ans = 0;
    for (auto [k, v] : mp) {
        // cout << k << ':' << v << endl; // debug
        ans += (long long)v * (v - 1) / 2;
    }
    ans -= M;

    cout << ans << endl;
    return 0;
}
/*
閉路を作っていく…？完全グラフに向かっていくと思えば良い？(2024/07/09 15:33:56)
全ての連結部分がそれぞれで完全グラフになると信じるか。(未検証)(2024/07/09 15:35:29)
Union-Findが妥当？BFS/DFSでも実装可能か。(2024/07/09 15:36:25)
久しぶりだしUnion-Findを思い出そう。(2024/07/09 15:36:39)
木構造にしてポインタ辿って親を求められるようにするくらいしか覚えていない。(2024/07/09 15:41:16)
19WA, 1TLEか。駄目ですね。(2024/07/09 16:00:27)
そもそも完全グラフにならないし、速度的にも遅い？(乃至ループ？)(2024/07/09 16:01:12)
Union-Findの実装が間違っているのかなあ()(2024/07/09 16:11:38)
あーUnion-Findが違うな。1-3-2のパターンで成立しない。(2024/07/09 16:14:30)
*/

