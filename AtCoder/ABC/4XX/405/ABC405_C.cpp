// 2025/05/23 11:26:52
// 2025/05/23 11:33:16 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<uint> A(N);
    for (uint &a : A) {
        cin >> a;
    }

    vector<uint> cumulative_sum(N);
    cumulative_sum[N - 1] = A[N - 1];
    for (int i = N - 2; 0 <= i; i--) {
        cumulative_sum[i] = cumulative_sum[i + 1] + A[i];
    }

    long long ans = 0;
    for (int i = 0; i <= N - 2; i++) {
        ans += (long long)A[i] * cumulative_sum[i + 1];
    }
    cout << ans << endl;
    return 0;
}
/*
overflowはしないのか？(2025/05/23 11:28:18)
かける数を先に足しておけば良いって話ね。(2025/05/23 11:28:42)
a b c d e f
a * (b + c + d + e + f) + b * (c + d + e + f) + c * (d + e + f) + ...
だからケツから累積和ね。(2025/05/23 11:29:26)
*/
