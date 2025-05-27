// 2025/03/10 21:25:27
// 2025/03/10 21:34:29 AC.
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }
    int s = A[0];
    for (int i = 1; i < N; i++) {
        s = gcd(s, A[i]);
    }
    int ans = 0;
    for (int a : A) {
        int d = a / s;
        while (d % 2 == 0) {
            d /= 2;
            ans++;
        }
        while (d % 3 == 0) {
            d /= 3;
            ans++;
        }
        if (d != 1) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}
/*
最大公約数を求めるだけだよね？(2025/03/10 21:26:40)
*/
