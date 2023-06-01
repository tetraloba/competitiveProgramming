//2022/09/05 07:33:21
//2022/09/05 07:37:42 WA
//2022/09/05 08:57:00 AC. 上限付き掛け算
//ABC169_B - Multiplication2
#include <iostream>
#include <vector>
#define NUM 1000000000000000000
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    long long ans = 1;
    for (long long i : A) {
        if (!i) {
            ans = 0;
            break;
        }
        if (i <= NUM / ans) {
            ans *= i;
        } else {
            ans = -1;
        }
    }
    cout << ans << endl;
    return 0;
}