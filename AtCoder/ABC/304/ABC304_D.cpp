// 2024/04/29 13:14:30
// 2024/04/29 13:55:00 23WA
// 2024/04/29 14:00:16 AC.
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main(){
    int W, H, N;
    cin >> W >> H >> N;
    vector<pair<int, int>> P(N);
    for (auto &p : P) {
        cin >> p.first >> p.second;
    }
    int A_size, B_size;
    cin >> A_size;
    vector<int> A(A_size);
    for (int &a : A) {
        cin >> a ;
    }
    cin >> B_size;
    vector<int> B(B_size);
    for (int &b : B) {
        cin >> b;
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    map<pair<int, int>, int> cnt;
    for (auto p : P) {
        int seg_x, seg_y;
        seg_x = lower_bound(A.begin(), A.end(), p.first) - A.begin();
        seg_y = lower_bound(B.begin(), B.end(), p.second) - B.begin();
        cnt[{seg_x, seg_y}]++;
    }
    int mi = INT32_MAX, ma = 0;
    for (auto [p, c] : cnt) {
        if (ma < c) {
            ma = c;
        }
        if (c < mi) {
            mi = c;
        }
    }
    if (cnt.size() < (long long)(A_size + 1) * (B_size + 1)) {
        mi = 0;
    }
    cout << mi << ' ' << ma << endl;
    return 0;
}
