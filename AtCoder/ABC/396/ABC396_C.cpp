// 2025/03/21 22:49:32
// 2025/03/21 22:58:20 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> B(N), W(M);
    for (int &b : B) {
        cin >> b;
    }
    for (int &w : W) {
        cin >> w;
    }
    sort(B.rbegin(), B.rend());
    sort(W.rbegin(), W.rend());
    long long ans = 0;
    int ib = 0;
    while (ib < N && 0 <= B[ib]) {
        ans += B[ib];
        ib++;
    }
    int iw = 0;
    while (iw < M && iw < ib) {
        if (W[iw] < 0) {
            break;
        }
        ans += W[iw];
        iw++;
    }
    while (ib < N && iw < M && 0 <= B[ib] + W[iw]) {
        ans += B[ib] + W[iw];
        ib++; iw++;
    }

    cout << ans << endl;
    return 0;
}
/*
ソートして取っていけば良さげ？(2025/03/21 22:51:34)
*/
