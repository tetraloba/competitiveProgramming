// 2024/04/15 21:03:24
// 2024/04/15 21:22:21 24WA
// 2024/04/15 21:48:35 24WA
// 
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<set<int>> P(N);
    for (int i = 0; i < N; i++) {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++) {
            int p;
            cin >> p;
            p--;
            P[i].insert(p);
        }
    }

    for (auto st : P) {
        for (int i : st) {
            cout << i << ' ';
        }
        cout << endl;
    }

    queue<int> que;
    vector<int> parent(N, -1);
    que.push(0);
    while (!que.empty()) {
        int tgt = que.front(); que.pop();
        for (int next : P[tgt]) {
            if (parent[next] == -1) {
                que.push(next);
            } else {
                P[parent[next]].erase(next);
            }
            parent[next] = tgt;
        }
    }
    // ここまでの処理で木になっているはず。

    for (auto st : P) {
        for (int i : st) {
            cout << i << ' ';
        }
        cout << endl;
    }

    vector<int> rseq;
    que.push(0);
    int t = 0; // time
    while (!que.empty()) {
        t--;
        int tgt = que.front(); que.pop();
        for (int next : P[tgt]) {
            rseq.push_back(next);
            que.push(next);
        }
    }
    vector<int> seq(rseq.rbegin(), rseq.rend());
    for (int id : seq) {
        cout << id + 1 << ' ';
    }
    cout << endl;
    return 0;
}
/*
2024/04/15 21:23:20
そうか、更新された時はやり直さなきゃいけないのか…
*/
