// 2025/05/23 11:13:01
// 2025/05/23 11:17:44 4WA
// 2025/05/23 11:26:24 AC.
#include <iostream>
#include <vector>
#include <set>
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

    vector<int> stk;
    stk.push_back(0);
    set<int> done;
    while (!stk.empty()) {
        int tgt = stk.back(); stk.pop_back();
        done.insert(tgt);
        if (G[tgt].size() != 2) {
            cout << "No" << endl;
            return 0;
        }
        for (int next : G[tgt]) {
            if (done.count(next)) {
                continue;
            }
            stk.push_back(next);
        }
    }
    cout << (done.size() == N ? "Yes" : "No") << endl;
    return 0;
}
/*
「それら以外の辺は存在しない」か。なら簡単そうだな。
「全ての頂点それぞれが、接続する辺の数が2本」ってのは必要十分？(2025/05/23 11:15:06)
あーそうか、連結じゃないと駄目か。6頂点が3と3に別れてそれぞれ三角形、みたいな。(2025/05/23 11:19:44)
*/
