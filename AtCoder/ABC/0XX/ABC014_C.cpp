// 2023/07/19 19:51:46
// 2023/07/19 19:58:26 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    const int N = 1000001;
    int n;
    cin >> n;
    vector<int> v(N);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[a]++;
        v[b + 1]--;
    }
    for (int i = 1; i < N; i++) {
        v[i] += v[i - 1];
    }
    int ans = 0;
    for (int i : v) {
        if (ans < i) {
            ans = i;
        }
    }
    cout << ans << endl;
    // cout <<  << endl;
    return 0;
}
