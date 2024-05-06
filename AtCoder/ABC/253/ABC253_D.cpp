// 2024/05/06 17:39:29
// 2024/05/06 17:50:12 AC.
#include <iostream>
#include <numeric>
using namespace std;
int main(){
    long long N, A, B;
    cin >> N >> A >> B;

    // cout << (1 + N) * N / 2 << endl; // debug
    long long ans = (1 + N) * N / 2;

    if (A < N) {
        // cout << (A + (N / A) * A) * (N / A) / 2 << endl; // debug
        ans -= (A + (N / A) * A) * (N / A) / 2;
    }

    if (B < N) {
        // cout << (B + (N / B) * B) * (N / B) / 2 << endl; // debug
        ans -= (B + (N / B) * B) * (N / B) / 2;
    }

    long long AB = lcm(A, B);
    if (AB < N) {
        // cout << (AB + (N / AB) * AB) * (N / AB) / 2 << endl; // debug
        ans += (AB + (N / AB) * AB) * (N / AB) / 2;
    }

    cout << ans << endl;
    return 0;
}
