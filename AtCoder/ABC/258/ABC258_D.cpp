// 2025/01/06 11:51:47
// 2025/01/06 12:35:55 18WA
// 2025/01/06 12:37:34 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, X;
    cin >> N >> X;
    vector<pair<int, int>> AB(N);
    for (auto &ab : AB) {
        cin >> ab.first >> ab.second;
    }

    long long ans = INT64_MAX;
    long long total_time = 0;
    int min_play_time = INT32_MAX;
    for (int i = 0; i < N; i++) {
        total_time += AB[i].first;
        min_play_time = min(min_play_time, AB[i].second);
        long long ans_cond = total_time + (long long)(X - i) * min_play_time;
        ans = min(ans, ans_cond);
        total_time += AB[i].second;
    }
    cout << ans << endl;
    return 0;
}
/*
途中で昼食食べてた…
*/
