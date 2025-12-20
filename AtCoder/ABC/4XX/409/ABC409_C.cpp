// 2025/12/20 20:54:15
// 2025/12/20 21:10:57 AC.
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main(){
    int N, L;
    cin >> N >> L;
    vector<int> D(N - 1);
    for (int& d : D) {
        cin >> d;
    }

    if (L % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> P(N);
    for (int i = 0; i < N - 1; i++) {
        P[i + 1] = (P[i] + D[i]) % L;
    }
    map<int, int> mpP; // {座標, 個数}
    for (int p : P) {
        mpP[p]++;
    }

    long long ans = 0;
    for (auto [p, n] : mpP) {
        if (L / 3 <= p) {
            break;
        }
        ans += (long long) n * mpP[p + L / 3] * mpP[p + L / 3 + L / 3];
    }

    cout << ans << endl;
    return 0;
}


