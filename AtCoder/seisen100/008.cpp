// 2025/03/02 10:16:47
// 2025/03/02 10:33:45 AC.
#include <iostream>
#include <vector>
#include <set>
using namespace std;
long long diff(int a, int b) {
    return a < b ? b - a : a - b;
}
int main(){
    int N;
    cin >> N;
    vector<pair<int, int>> AB(N);
    set<int> st;
    for (auto &ab : AB) {
        cin >> ab.first >> ab.second;
        st.insert(ab.first);
        st.insert(ab.second);
    }
    long long ans = INT64_MAX;
    for (int enter : st) {
        for (int exit : st) {
            long long cand = 0;
            for (auto [a, b] : AB) {
                cand += min(diff(enter, a) + diff(a, b) + diff(b, exit), diff(enter, b) + diff(b, a) + diff(a, exit));
            }
            ans = min(ans, cand);
        }
    }
    cout << ans << endl;
    return 0;
}
/*
探索するの，AiかBiに含まれるところだけで良い説無い？根拠は無い(2025/03/02 10:25:43)
*/

