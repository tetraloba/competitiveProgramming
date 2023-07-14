// 2023/07/14 19:25:29
// 2023/07/14 20:36:36 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    vector<long long> sum(N + 1);
    sum[0] = 0;
    for (int i = 1; i < sum.size(); i++) {
        sum[i] = sum[i - 1] + a[i - 1];
    }
    // for (int i = 0; i < sum.size(); i++) {
    //     cout << sum[i] << endl;
    // }
    long long ans = 0;
    for (int i = K; i < sum.size(); i++) {
        ans += sum[i] - sum[i - K];
        // cout << sum[i] << ' ' << sum[i - K] << ' ' << ans << endl;
    }
    cout << ans << endl;
    return 0;
}