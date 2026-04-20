// 2026/04/20 21:22:46
// 2026/04/20 09:27:06 10WA
// 2026/04/20 09:28:14 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> C(N, N - 1);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        C[a]--;
        C[b]--;
    }
    for (int i = 0; i < N; i++) {
        if (C[i] < 3) {
            cout << 0 << ' ';
        } else {
            cout << (long long)C[i] * (C[i] - 1) * (C[i] - 2) / (3 * 2 * 1) << ' ';
        }
    }
    cout << endl;
    return 0;
}
