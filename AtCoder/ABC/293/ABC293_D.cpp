// 2024/04/17 21:12:38
// 2024/04/17 21:51:33 21WA
// 2024/04/17 22:08:02 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> G(N, {-1, -1});
    for (int i = 0; i < M; i++) {
        int a, c;
        char b, d;
        cin >> a >> b >> c >> d;
        a--;
        c--;
        if (G[a].first == -1) {
            G[a].first = c;
        } else {
            G[a].second = c;
        }
        if (G[c].first == -1) {
            G[c].first = a;
        } else {
            G[c].second = a;
        }
    }

    // for (auto [a, b] : G) {
    //     cout << a << ' ' << b << endl;
    // }

    vector<bool> done(N);
    int cnt_1 = 0, cnt_2 = 0;
    for (int i = 0; i < N; i++) {
        if (done[i]) {
            continue;
        }
        done[i] = true;
        int tgt = G[i].first, pre = i;
        bool loop = false;
        while (tgt != -1) {
            done[tgt] = true;
            if (pre == G[tgt].first) {
                pre = tgt;
                tgt = G[tgt].second;
            } else {
                pre = tgt;
                tgt = G[tgt].first;
            }
            if (tgt == i) {
                loop = true;
                break;
            }
        }
        if (!loop) {
            tgt = G[i].second;
            pre = i;
            while (tgt != -1) {
                done[tgt] = true;
                if (pre == G[tgt].first) {
                    pre = tgt;
                    tgt = G[tgt].second;
                } else {
                    pre = tgt;
                    tgt = G[tgt].first;
                }
            }
        }
        (loop ? cnt_1 : cnt_2)++;
    }
    cout << cnt_1 << ' ' << cnt_2 << endl;
    return 0;
}
/*
1
2     B
3 R B
4     R
5 B R

赤か青かって区別する必要なくない？(2024/04/17 21:18:19)
普通に閉路を判定する問題か。(2024/04/17 21:18:47)
*/
