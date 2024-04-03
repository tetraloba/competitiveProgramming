// 2024/04/03 16:36:55
// 2024/04/03 17:06:50 AC.
#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N), B(N), X(N);
    vector<set<pair<int, int>>> G(N); // 時間, ステージ
    for (int i = 0; i < N - 1; i++) {
        int A, B, X;
        cin >> A >> B >> X;
        X--;
        G[i].insert({A, i + 1});
        G[i].insert({B, X});
    }

    /* ダイクストラ法 */
    vector<long long> T(N, INT64_MAX); // 各ステージの最速到達時間
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pque; // 到達時間, ステージ
    T[0] = 0; // ステージ0は0秒
    pque.push({0, 0});
    while (!pque.empty()) {
        pair<long long, int> tgt = pque.top(); pque.pop();
        for (pair<int, int> next : G[tgt.second]) {
            long long next_time = tgt.first + next.first;
            if (next_time < T[next.second]) {
                T[next.second] = next_time;
                pque.push({next_time, next.second});
            }
        }
    }
    cout << T[N - 1] << endl;
    return 0;
}
/*
動的計画法やなあ(2024/04/03 16:38:01)
実装が分からん。グラフにして最短経路問題(ダイクストラ法)にした方が分かりやすいかな？
まあ実装の練習も兼ねてやってみるか。(2024/04/03 16:47:28)
*/
