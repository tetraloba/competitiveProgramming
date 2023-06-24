// 2023/06/24 19:04:03
// 2023/06/24 19:56:20 AC.
#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    vector<int> v;
    while (1 < K) {
        v.push_back(K);
        K = K / 2 + K % 2;
    }
    v.push_back(1);
    for (int i : v) {
        cerr << i << ' ';
    }
    cerr << endl;
    vector<double> anses(N);
    int i = N - 1;
    double p = 1;
    for (auto itr = v.begin(); itr != v.end(); itr++) {
        while (*itr <= i + 1) {
            anses[i] = p;
            i--;
        }
        p /= 2;
    }
    double ans = 0;
    for (double i : anses) {
        // cerr << i << ' ';
        ans += i;
    }
    // cerr << endl;
    cout << setprecision(11) << ans / N << endl;
    return 0;
}
// 1 2 4 8 16
// 2 4 8 16
// 3 6 12 24

// 10 5 2 1
// 13 6 3 1