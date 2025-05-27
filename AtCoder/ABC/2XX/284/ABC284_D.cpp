// 2024/05/12 21:33:50
// 2024/05/12 22:34:39 11WA
// 2024/05/12 22:39:48 10WA
// 2024/05/12 22:54:22 AC
#include <iostream>
#define rN_MAX 3000000000
using namespace std;
long long sqrt(long long N){
    long long l = 2, r = rN_MAX;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (mid * mid == N) {
            return mid;
        } else if (mid * mid < N) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}
int main(){
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        long long N;
        cin >> N;
        for (long long p = 2; p < rN_MAX; p++) {
            if (N % p) {
                continue;
            }
            if (N / p % p) {
                cout << sqrt(N / p) << ' ' << p << endl;
            } else {
                cout << p << ' ' << N / p / p << endl;
            }
            break;
        }
    }
    return 0;
}
