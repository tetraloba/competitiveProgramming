// 2024/07/19 22:37:34
// 2024/07/19 22:42:13 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N), W(N);
    for (int &a : A) {
        cin >> a;
        a--;
    }
    for (int &w : W) {
        cin >> w;
    }

    vector<int> maxs(N);
    for (int i = 0; i < N; i++) {
        maxs[A[i]] = max(maxs[A[i]], W[i]);
    }
    int sum = 0;
    for (int w : W) {
        sum += w;
    }
    int ans = sum;
    for (int max : maxs) {
        ans -= max;
    }

    cout << ans << endl;
    return 0;
}
