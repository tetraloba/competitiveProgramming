// 2024/10/11 11:04:31
// 2024/10/11 12:17:47 AC.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int N, X, Y;
    cin >> N >> X >> Y;
    X--; Y--;

    vector<vector<int>> G(N);
    for (int i = 0; i < N - 1; i++) {
        G[i].push_back(i + 1);
        G[i + 1].push_back(i);
    }
    G[X].push_back(Y);
    G[Y].push_back(X);

    vector<int> K(N);
    for (int i = 0; i < N; i++) {
        vector<bool> done(N);
        queue<pair<int, int>> que;
        que.push({i, 0});
        done[i] = true;
        while (!que.empty()) {
            auto [tgt, dist] = que.front(); que.pop();
            if (i < tgt) {
                K[dist]++;
            }
            for (int next : G[tgt]) {
                if (!done[next]) {
                    que.push({next, dist + 1});
                    done[next] = true;
                }
            }
        }
    }

    for (int i = 1; i <= N - 1; i++) {
        cout << K[i] << endl;
    }
    return 0;
}
/*
全頂点間の最短距離を求めるってこと？ (2024/10/11 11:06:29)
N<=2000ならいけるか・・・
*/
