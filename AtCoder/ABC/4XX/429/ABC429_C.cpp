// 2025/12/12 20:56:47
// 2025/12/12 21:12:07 WA overflow
// 2025/12/12 21:12:53 AC.
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }

    map<int, int> cnt;
    for (int a : A) {
        cnt[a]++;
    }

    long long ans = 0;
    for (auto [_, n] : cnt) {
        if (n < 2) {
            continue;
        }
        /* 2個の選び方 */
        long long choose2 = (long long)n * (n - 1) / 2;
        /* 残り1個の選び方 */
        long long choose1 = N - n;
        ans += choose2 * choose1;
    }

    cout << ans << endl;
    return 0;
}
/*
2025/12/12 21:06:16
組み合わせだから順番関係ないのかしら。
mapで数え上げて計算してGGかな。
*/
