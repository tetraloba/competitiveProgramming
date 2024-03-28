// 2024/03/28 14:34:02
// 2024/03/28 14:48:24 1WA
// 2024/03/28 14:51:35 AC.
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    int N, T;
    cin >> N >> T;
    vector<int> A(T), B(T);
    for (int i = 0; i < T; i++) {
        int a, b;
        cin >> a >> b;
        A[i] = --a; B[i] = b;
    }

    int ans = 1;
    vector<long long> scores(N); // 各選手の得点
    map<long long, int> mp; // 得点とその人数
    mp[0] = N;
    for (int i = 0; i < T; i++) {
        mp[scores[A[i]]]--;
        if (mp[scores[A[i]]] == 0) {
            ans--;
        }
        scores[A[i]] += B[i];
        mp[scores[A[i]]]++;
        if (mp[scores[A[i]]] == 1) {
            ans++;
        }
        cout << ans << endl;
        // /* debug */
        // for (auto [k, v] : mp) {
        //     cout << '(' << k << ',' << v << ')';
        // }
        // cout << endl;
    }
    return 0;
}
/*
mapで点数とその人数を管理して各Biに対してO(log(N))で更新していけば良さそう。(2024/03/28 14:36:15)
0 0 0
10 0 0
10 0 20
10 10 20
10 20 20

1WA
killerって何だよ物騒な・・・
普通にoverflowしていそうな気もするのだけれど。
普通にoverflowでした。
*/
