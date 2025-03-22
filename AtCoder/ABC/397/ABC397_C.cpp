// 2025/03/22 10:57:10
// 2025/03/22 11:08:02 AC.
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }

    vector<int> v_l(N), v_r(N);
    set<int> st_l, st_r;
    v_l[0] = 0;
    for (int i = 1; i < N; i++) {
        if (st_l.find(A[i - 1]) == st_l.end()) {
            st_l.insert(A[i - 1]);
            v_l[i] = v_l[i - 1] + 1;
        } else {
            v_l[i] = v_l[i - 1];
        }
    }
    st_r.insert(A[N - 1]);
    v_r[N - 1] = 1;
    for (int i = N - 2; 0 <= i; i--) {
        if (st_r.find(A[i]) == st_r.end()) {
            st_r.insert(A[i]);
            v_r[i] = v_r[i + 1] + 1;
        } else {
            v_r[i] = v_r[i + 1];
        }
    }

    /* debug */
    for (int i : v_l) {
        cerr << i << ' ';
    }
    cerr << endl;
    for (int i : v_r) {
        cerr << i << ' ';
    }
    cerr << endl;

    int ans = 0;
    for (int i = 1; i < N; i++) {
        ans = max(ans, v_l[i] + v_r[i]);
    }
    cout << ans << endl;
    return 0;
}
/*
両辺から数え上げれば良いのでは？(2025/03/22 10:58:25)
*/

