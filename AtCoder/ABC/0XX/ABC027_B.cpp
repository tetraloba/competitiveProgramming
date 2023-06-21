// 2023/06/21 20:00:15
// 2023/06/21 20:13:48 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int sum = 0;
    for (int i : a) {
        sum += i;
    }
    if (sum % N) {
        cout << -1 << endl;
        return 0;
    }
    int T = sum / N; // 目標人数
    int sum_sub = 0;
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        sum_sub += a[i];
        cnt++;
        if (sum_sub == cnt * T) {
            sum_sub = 0;
            cnt = 0;
        } else {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}