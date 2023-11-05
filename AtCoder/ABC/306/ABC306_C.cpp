// 2023/11/05 12:15:47
// 2023/11/05 12:21:17 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(3 * N);
    for (int i = 0; i < 3 * N; i++) {
        cin >> A[i];
    }
    vector<int> cnt(N);
    vector<pair<int, int>> fi(N);
    for (int i = 0; i < 3 * N; i++) {
        cnt[A[i] - 1]++;
        if (cnt[A[i] - 1] == 2) {
            fi[A[i] - 1] = make_pair(i, A[i]);
        }
    }
    sort(fi.begin(), fi.end());
    for (auto [i, x] : fi) {
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}