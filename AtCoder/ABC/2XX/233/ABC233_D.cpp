// 2024/04/09 10:17:43
// 
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }
    vector<int> sum_l(N), sum_r(N);
    sum_l[0] = A[0];
    for (int i = 1; i < N; i++) {
        sum_l[i] = sum_l[i - 1] + A[i];
    }
    sum_r[N - 1] = A[N - 1];
    for (int i = N - 2; 0 <= i; i--) {
        sum_r[i] = sum_r[i + 1] + A[i];
    }
    int l = 0, r = 0;
    long long sum = A[0];
    int ans = 0;
    while (r < N) {
        if (sum == K) {
            ans++;
        }
        sum += A[++r];
        while (l < r && K < sum) {
            if ((K < sum && 0 <= A[l]))
            sum -= A[l++];
        }
    }
    cout << ans << endl;
    return 0;
}
/*
尺取法だっけ？(2024/04/09 10:18:31)
負があるとややこしいのか？累積和で良い？(2024/04/09 10:31:22)
累積和でもO(N^2)は同じか。
ちょっと工夫して尺取法書くしか無いか。(2024/04/09 10:37:05)
N=200,000 K=0 でAが全部0だと数え上げは間に合わないか。(2024/04/09 10:48:37)
部分和を高速に求める方法ってなんだっけ。セグ木…？(2024/04/09 10:49:22)
分からん。解説見る。(2024/04/09 10:56:08)
*/
