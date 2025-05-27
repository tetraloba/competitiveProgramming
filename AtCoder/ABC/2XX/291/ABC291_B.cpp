//2023/04/04 21:11:47
//2023/04/04 21:26:08 AC.
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> X(5 * N);
    int tmp;
    for (int i = 0; i < 5 * N; i++) {
        cin >> X[i];
    }
    sort(X.begin(), X.end());
    // cout << "debug: " << accumulate(&X[N], &X[4 * N], 0) << endl;
    cout << fixed;
    cout << setprecision(6) << (double)accumulate(&X[N], &X[4 * N], 0) / (3 * N) << endl;
    return 0;
}