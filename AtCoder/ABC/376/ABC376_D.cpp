// 2024/11/25 19:18:10
// 2024/11/25 20:14:17 19AC 20WA
// 2024/11/25 20:26:55 15AC 24WA
// 2024/11/25 20:45:05 AC.
#include <iostream>
#include <vector>
#include <set>
#include <queue>
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
    }

    vector<bool> done(N); // ある頂点について処理したかどうか
    queue<pair<int, int>> que; // 距離, 頂点
    que.push({0, 0});
    // done[0] = true; // しなくて良い
    while (!que.empty()) {
        auto [dist, tgt] = que.front(); que.pop();
        // cerr << dist << ' ' << tgt << endl; // debug
        for (int next : G[tgt]) {
            // cerr << "next: " << next << endl; // debug
            if (done[next]) {
                continue;
            }
            if (next == 0) {
                cout << dist + 1 << endl;
                return 0;
            }
            que.push({dist + 1, next});
            done[next] = true;
        }
    }
    cout << -1 << endl;
    return 0;
}
/*
頂点1から頂点1への最短経路問題として解ける？
頂点1は処理済みとしてマークしないで、ただし行って返ってくるだけは禁止。
ダイクストラでO(NlogN)なら解けないことはないだろう。(2024/11/25 19:21:32)
あ駄目だわ。同じ頂点を通らないからループしないのか。(2024/11/25 19:36:36)
じゃあ同じ点に達したときに判定する？
いやY字の場合は同じ頂点にぶつかっても頂点1を含む閉路ではないか。(2024/11/25 19:47:51)
有向グラフなことを忘れていた。有向グラフならやはり元の「頂点1から頂点1への最短経路問題」に戻せないか…？(2024/11/25 20:21:29)
っていうか重みがないからダイクストラじゃなくてただの幅優先探索じゃん・・・(2024/11/25 20:39:35)
*/
/*
問題を難しくしすぎたな。これって無向グラフだと難しいのか…？(2024/11/25 20:46:11)
*/
