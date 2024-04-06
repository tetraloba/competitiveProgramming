// 2024/04/06 21:01:40
// 2024/04/06 21:06:16 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<pair<int, int>> V(N);
    for (int i = 0; i < N; i++) {
        cin >> V[i].first >> V[i].second;
    }
    for (int i = 0; i < N; i++) {
        int ans_i;
        long long ans_dist = 0;
        for (int j = 0; j < N; j++) {
            long long dist = (long long)(V[i].first - V[j].first) * (V[i].first - V[j].first) + (long long)(V[i].second - V[j].second) * (V[i].second - V[j].second);
            if (ans_dist < dist) {
                ans_dist = dist;
                ans_i = j + 1;
            }
        }
        cout << ans_i << endl;
    }
    return 0;
}
/*
全探索で間に合うので問題文の通りに素直に実装しましょう。
*/
