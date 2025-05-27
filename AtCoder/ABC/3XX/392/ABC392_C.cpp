// 2025/02/25 13:22:53
// 2025/02/25 13:30:36 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> P(N), Q(N);
    for (int &p : P) {
        cin >> p;
    }
    for (int &q : Q) {
        cin >> q;
    }
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        v[Q[i] - 1] = P[i];
    }
    for (int i : v) {
        cout << Q[i - 1] << ' ';
    }
    cout << endl;
    return 0;
}
