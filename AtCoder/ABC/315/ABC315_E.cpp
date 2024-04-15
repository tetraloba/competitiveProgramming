// 2024/04/15 21:03:24
// 2024/04/15 21:22:21 24WA
// 2024/04/15 21:48:35 24WA
// 2024/04/15 22:26:29 TLE
// 2024/04/15 22:49:51 AC.
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> C(N);
    vector<set<int>> P(N), rP(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
        for (int j = 0; j < C[i]; j++) {
            int p;
            cin >> p;
            p--;
            P[i].insert(p);
            rP[p].insert(i);
        }
    }

    vector<bool> part_of_0(N);
    queue<int> que;
    /* 0の前提となる本の集合(part_of_0[i] == true)を求める */
    que.push(0);
    part_of_0[0] = true;
    while (!que.empty()) {
        int tgt = que.front(); que.pop();
        for (int next : P[tgt]) {
            if (!part_of_0[next]) {
                que.push(next);
                part_of_0[next] = true;
            }
        }
    }

    /* 0の前提集合で前提本が無い本を最初に読む */
    for (int i = 0; i < N; i++) {
        if (part_of_0[i] && !C[i]) {
            que.push(i);
        }
    }
    while (!que.empty()) {
        int tgt = que.front(); que.pop();
        if (tgt) { // (0は出力しない)
            cout << tgt + 1 << ' ';
        }
        for (int next : rP[tgt]) {
            C[next]--; // 前提本を1つ(tgt)読み終わった
            /* 前提本を全て読み終わったなら読書キューに追加 */
            if (part_of_0[next] && !C[next]) {
                que.push(next);
            }
        }
    }
    cout << endl;
    return 0;
}
/*
2024/04/15 21:23:20
そうか、更新された時はやり直さなきゃいけないのか…
*/
