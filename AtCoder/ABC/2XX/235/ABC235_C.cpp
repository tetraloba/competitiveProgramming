// 2023/06/09 10:37:01
// 2023/06/09 11:02:53 TLE find()はO(N)じゃないか(笑)
// 2023/06/09 11:14:24 RE 1件のRE。itrの範囲外アクセスかしら。
// 2023/06/09 11:23:31 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, Q;
    cin >> N >> Q;
    vector<pair<int, int>> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(A.begin(), A.end());
    // for (int i = 0; i < N; i++) {
    //     cout << A[i].first << ':' << A[i].second << endl;
    // }
    for (int i = 0; i < Q; i++) {
        int x, k;
        cin >> x >> k;
        auto itrF = lower_bound(A.begin(), A.end(), make_pair(x, numeric_limits<int>::min()));
        auto itrE = upper_bound(A.begin(), A.end(), make_pair(x, numeric_limits<int>::max()));
        if (itrF != A.end() && k - 1 <= (itrE - itrF)) {
            if ((*(itrF + (k - 1))).first == x) {
                cout << (*(itrF + (k - 1))).second + 1 << endl;
            } else {
                cout << -1 << endl;
            }
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}