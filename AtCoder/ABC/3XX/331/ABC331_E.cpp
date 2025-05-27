// 2025/04/06 09:36:36
// 2025/04/06 09:57:06 18WA 2RE
// 2025/04/06 09:59:02 15WA
// 2025/04/06 10:07:28 AC.
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int solve1_ab(const vector<pair<int, int>>& sortedA, const vector<pair<int, int>>& sortedB, const vector<set<int>>& C) {
    int ans = 0;
    for (int i = 0; i < sortedA.size(); i++) {
        for (int j = 0; j < sortedB.size(); j++) {
            // cerr << sortedA[i].second << ' ' << sortedB[j].second << ' ';
            if (C[sortedA[i].second].count(sortedB[j].second)) {
                // cerr << "No" << endl;
                continue;
            }
            ans = max(ans, sortedA[i].first + sortedB[j].first);
            break;
        }
    }
    return ans;
}
int main() {
    int N, M, L;
    cin >> N >> M >> L;
    vector<int> A(N);
    vector<int> B(M);
    for (int &a : A) {
        cin >> a;
    }
    for (int &b : B) {
        cin >> b;
    }
    vector<set<int>> Cab(N);
    vector<set<int>> Cba(M);
    for (int i = 0; i < L; i++) {
        int c, d;
        cin >> c >> d;
        c--; d--;
        Cab[c].insert(d);
        Cba[d].insert(c);
    }

    vector<pair<int, int>> sortedA(N);
    for (int i = 0; i < N; i++) {
        sortedA[i] = {A[i], i};
    }
    sort(sortedA.rbegin(), sortedA.rend());
    vector<pair<int, int>> sortedB(M);
    for (int i = 0; i < M; i++) {
        sortedB[i] = {B[i], i};
    }
    sort(sortedB.rbegin(), sortedB.rend());
    /* debug */
    // for (auto a : sortedA) {
    //     cerr << '(' << a.first << ',' << a.second << ')' << ' ';
    // }
    // cerr << endl;
    // for (auto b : sortedB) {
    //     cerr << '(' << b.first << ',' << b.second << ')' << ' ';
    // }
    // cerr << endl;

    cout << max(solve1_ab(sortedA, sortedB, Cab), solve1_ab(sortedB, sortedA, Cba)) << endl;
    return 0;
}
/*
Lが高々10^5なら貪欲で良いのでは？(2025/04/06 09:39:09)
あーそうか，5-1より4-4の方が良いよねって話か(2025/04/06 10:06:04)
*/
