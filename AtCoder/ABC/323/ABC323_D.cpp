// 2024/03/01 21:20:27
// 2024/03/01 21:55:05 TLE
// 2024/03/01 22:26:58 AC.
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> S(N), C(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i] >> C[i];
    }
    map<long long, long long> mp;
    for (int i = 0; i < N; i++) {
        mp[S[i]] = C[i];
    }
    long long ans = 0;
    map<long long, bool> done;
    for (auto &[k, v] : mp) {
        if (done.count(k)) {
            continue;
        }
        long long tgt_key = k;
        long long slime = 0;
        slime += mp[tgt_key];
        done[tgt_key] = true;
        while (slime) {
            ans += slime % 2;
            slime /= 2;
            tgt_key *= 2;
            slime += mp[tgt_key];
            done[tgt_key] = true;
        }
    }
    // /* debug */
    // for (auto [k, v] : mp) {
    //     cout << '(' << k << ',' << v << ')' << '\n';
    // }
    // cout << endl;
    // for (auto [k, v] : mp) {
    //     ans += v;
    // }
    cout << ans << endl;
    return 0;
}