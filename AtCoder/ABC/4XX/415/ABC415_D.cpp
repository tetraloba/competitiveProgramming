// 2025/12/15 17:39:18
// 2025/12/15 18:12:58 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    long long N, M;
    cin >> N >> M;
    vector<long long> A(M), B(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
    }

    vector<pair<long long, long long>> stk;
    for (int i = 0; i < M; i++) {
        stk.push_back({A[i] - B[i], A[i]});
    }
    sort(stk.rbegin(), stk.rend());

    long long n = N;
    long long ans = 0;
    while (!stk.empty()) {
        auto [cost, limit] = stk.back(); stk.pop_back();
        long long num = max(0ll, n - limit) / cost;
        n -= num * cost;
        if (limit <= n) {
            num++;
            n -= cost;
        }
        ans += num;
        // cerr << cost << ' ' << limit << ' ' << num << ' ' << ans << ' ' << n << endl; // debug
        if (!n) {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
/*
2025/12/15 17:40:42
DPかなあ()
2025/12/15 17:44:06
Ai本渡してBi本貰うことは、(Ai-Bi)本消費することと同義か。ただしAi本以上持っていないと使えないという制約。
2025/12/15 17:46:06
(Ai,Bi)を(Ai,Ai-Bi)に置き換えておいて、Aiの降順でソートする。
いやAiでソートしない方が良いな。Ai-Biで昇順ソートか、PriorityQueueで良い。
消費(Ai-Bi)が小さいもので、かつ現在のAiを満たすものであれば可能なだけ実行する。
Ai条件を満たさなくなったら破棄して、次の条件を取得する。
*/
