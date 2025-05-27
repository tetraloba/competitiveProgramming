// 2024/12/02 09:25:03
// 2024/12/02 09:41:11 AC.
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    int N;
    cin >> N;
    int sum = 0;
    vector<int> K(N);
    for (int &k : K) {
        cin >> k;
        sum += k;
    }
    /* 組み合わせ全探索 */
    long long ans = 2e9;
    int maxC = pow(2, 20);
    for (int C = 0; C < maxC; C++) {
        long long ans_con = 0; // 候補
        for (int i = 0; i < N; i++) {
            if ((C >> i) % 2) {
                ans_con += K[i];
            }
        }
        ans = min(ans, max(ans_con, sum - ans_con));
    }
    cout << ans << endl;
    return 0;
}
/*
3,5,2,2,2,2
は
3,5
2,2,2,2
で詰めないといけないのよな…
明らかにO(NK)だが・・・(メタ読み) (2024/12/02 09:31:21)
組み合わせ問題的にも、すごくDPっぽいしね。 (2024/12/02 09:32:05)
2^20 = 1e6 え、間に合うのか… (2024/12/02 09:33:12)
組み合わせ全探索？bitで？ (2024/12/02 09:33:40)
*/
