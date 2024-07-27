// 2024/07/25 12:58:49
// 2024/07/25 13:18:14 17WA
// 2024/07/25 13:19:32 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, T;
    cin >> N >> T;
    string S;
    cin >> S;
    vector<int> X(N);
    for (int &x : X) {
        cin >> x;
    }

    vector<int> posi, nega;
    for (int i = 0; i < N; i++) {
        (S[i] == '1' ? posi : nega).push_back(X[i]);
    }

    sort(posi.begin(), posi.end());
    sort(nega.begin(), nega.end());

    long long ans = 0;
    auto l = nega.begin(), r = l;
    for (int p : posi) {
        while (l != nega.end() && *l < p) {
            l++;
        }
        while (r != nega.end() && *r <= p + 2 * T) {
            r++;
        }
        ans += r - l;
    }
    cout << ans << endl;
    return 0;
}
/*
正組と負組で分けて、
自分以上自分+2Tまでの相手組とすれ違う。
片方の組だけやればいいね。(2024/07/25 13:02:18)
ソートしておけば範囲の始点と終点がスライドしていくだけなのでO(N)でいけるだろうね。
もちろんソートが有るので全体はO(N log N)だが。(2024/07/25 13:04:51)
*/
/*
あーこれ尺取法と言えるのか。
*/
