// 2024/05/06 14:49:40
// 2024/05/06 15:04:09 12WA
// 2024/05/06 15:31:52 AC.
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<stack<int>> G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push(b);
        G[b].push(a);
    }
    vector<bool> done(N);
    for (int i = 0; i < N; i++) {
        if (done[i]) {
            continue;
        }
        if (1 < G[i].size()) {
            continue; // 端でないならスキップ
        }
        done[i] = true;
        if (G[i].size() == 0) {
            continue;
        }
        int tgt = G[i].top();
        bool finish = false;
        while (!finish) {
            done[tgt] = true;
            switch (G[tgt].size()) {
                case 0: // あり得ない
                case 1:
                    finish = true;
                    break;
                case 2:
                    if (done[G[tgt].top()]) {
                        G[tgt].pop();
                    }
                    tgt = G[tgt].top();
                    if (done[tgt]) {
                        cout << "No" << endl;
                        return 0;
                    }
                    done[tgt] = true;
                    break;
                default:
                    cout << "No" << endl;
                    return 0;
            }
        }
    }
    for (bool d : done) {
        if (!d) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
/*
グラフにした時に次元の最大値が2以下で、閉路がなければ良し？(2024/05/06 14:50:48)
*/
