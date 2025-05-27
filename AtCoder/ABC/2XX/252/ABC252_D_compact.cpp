// 2024/04/24 22:24:08
// 2024/04/24 23:47:25 4WA
// 2024/04/24 23:52:07 1WA
// 2024/04/24 23:58:24 AC.
#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll=long long;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &a : A) cin >> a;

    map<int, ll> cnt; // 累計登場回数
    for (int a : A) cnt[a]++;

    int r = N; // 3つ目の候補数
    ll d = 0; // 重複数
    map<int, ll> apr; // 以左登場回数
    ll ans = 0;
    for (int a : A) {
        r--;
        cnt[a]--;
        ans += (r - cnt[a]) * (N - r - 1 - apr[a]) - d + (cnt[a] + 1) * apr[a];
        d += cnt[a] - apr[a];
        apr[a]++;
    }
    cout << ans << endl;
    return 0;
}
