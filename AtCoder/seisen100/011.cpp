// 2025/01/12 21:29:11
// 2025/01/12 21:56:18 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector connected_bulbs = vector(N, vector<int>());
    for (int m = 0; m < M; m++) {
        int k;
        cin >> k;
        for (int i = 0; i < k; i++) {
            int s;
            cin >> s;
            s--;
            connected_bulbs[s].push_back(m);
        }
    }

    int ideal_bulbs = 0;
    for (int m = 0; m < M; m++) {
        int p;
        cin >> p;
        ideal_bulbs |= p << m;
    }

    int ans = 0;
    int C_MAX = 1 << N;
    for (int C = 0; C < C_MAX; C++) {
        int actual_bulbs = 0;
        for (int n = 0; n < N; n++) {
            if (C >> n & 1) {
                for (int bulb : connected_bulbs[n]) {
                    actual_bulbs ^= 1 << bulb;
                }
            }
        }
        if (ideal_bulbs == actual_bulbs) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
