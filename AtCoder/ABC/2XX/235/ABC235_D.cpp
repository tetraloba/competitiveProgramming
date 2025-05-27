// 2024/04/22 18:30:51
// 2024/04/22 19:03:02 AC.
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
int main(){
    int a, N;
    cin >> a >> N;
    long long s = 1;
    queue<pair<long long, long long>> que;
    long long ans = INT64_MAX;
    set<long long> done;
    que.push({s, 0});
    done.insert(s);
    while (!que.empty()) {
        auto [tgt, i] = que.front(); que.pop();
        // cout << tgt << ' ';
        if (tgt == N) {
            ans = min(ans, i);
        }
        int r = tgt % 10;
        long long coefficient = 10;
        long long tmp = tgt / 10;
        if (tgt / 10 && r) {
            while (tmp / coefficient) {
                coefficient *= 10;
            }
            tmp += r * coefficient;
            if (tmp < N * 10 && !done.count(tmp)) {
                que.push({tmp, i + 1});
                done.insert(tmp);
            }
        }
        tmp = tgt * a;
        if (tmp < N * 10 && !done.count(tmp)) {
            que.push({tmp, i + 1});
            done.insert(tmp);
        }
    }
    cout << (ans == INT64_MAX ? -1 : ans) << endl;
    return 0;
}
