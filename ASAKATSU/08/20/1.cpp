//2022/08/20 07:30:07
//2022/08/20 08:27:43 AC.
//ARC112_A - B = C
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int L, R;
        cin >> L >> R;
        if (R < L * 2) {
            cout << 0 << endl;
            continue;
        }
        int N = (R - 2 * L) + 1;
        cout << (long long)(N + 1) * N / 2 << endl;
    }
    return 0;
}
// L + L
// L + (L + 1)
// ...
// L + (L + ?) == R
// // R - 2L 個
// R-2L + R-2L-1 + ...??
// 2 2
// 2 3
// 2 4
// 3 2
// 3 3
// 4 2

// 2
// 0 0
// 0 1
// 0 2
// 1 0
// 1 1
// 2 0

// 3
// 0 0
// 0 1
// 0 2
// 0 3
// 1 0
// 1 1
// 1 2
// 2 0
// 2 1
// 3 0
// 4 3 2 1
