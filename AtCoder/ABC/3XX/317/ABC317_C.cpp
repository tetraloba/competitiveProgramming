// 2024/03/24 09:05:58
// 2024/03/24 09:50:10 AC.
#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<set<pair<int, int>>> vs(N);
    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        vs[--A].insert({--B, C});
        vs[B].insert({A, C});
    }
    // /* debug */
    // for (int i = 0; i < N; i++) {
    //     cout << i << ':';
    //     for (auto [f, s] : vs[i]) {
    //         cout << '(' << f << ',' << s << ')';
    //     }
    //     cout << '\n' << endl;
    // }
    int ans = 0;
    stack<pair<vector<int>, int>> trace;
    for (int i = 0; i < N; i++) {
        trace.push({vector<int>(1, i), 0});
        while (!trace.empty()) {
            auto [route, dist] = trace.top(); trace.pop();
            // /* debug */
            // for (int r : route) {
            //     cout << r << ' ';
            // }
            // cout << '(' << dist << ')' << endl;
            int tgt = route.back(); // 現在地
            route.push_back(N);
            for (auto [c, d] : vs[tgt]) {
                if (find(route.begin(), route.end(), c) == route.end()) { // O(N)
                    route.back() = c;
                    dist += d;
                    trace.push({route, dist});
                    if (ans < dist) {
                        ans = dist;
                    }
                    dist -= d;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
/*
深さ優先探索で解けるかな。
幅優先のほうが美しいか。(2024/03/24 09:08:30)
いや他のルートで辿り着いた場所も行くから違うのかな…
全探索するとしたらO(10!)か。(2024/03/24 09:11:24)
3,628,800って、間に合わない、よね…？
DFSのスタックに経路情報詰め込めるのかなあ…
*/
