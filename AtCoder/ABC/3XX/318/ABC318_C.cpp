// 2024/03/02 20:41:57
// 2024/03/02 20:57:00 WA1 RE2
// 2024/03/02 21:03:03 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, D, P;
    cin >> N >> D >> P;
    vector<int> F(N);
    for (int &f : F) {
        cin >> f;
    }
    sort(F.rbegin(), F.rend()); // 降順ソート
    vector<long long> F_sum(N + 1); // 累積和 ケツから
    F_sum[N] = 0;
    for (int i = N - 1; 0 <= i; i--) {
        F_sum[i] = F_sum[i + 1] + F[i];
    }

    int bs_num = 0;
    while ((bs_num + D < N ? F_sum[bs_num + D] : 0) + P < F_sum[bs_num]) {
        bs_num += D;
        if (N <= bs_num) {
            break;
        }
    }
    cout << (bs_num ? (long long)bs_num / D * P : 0) + (bs_num < N ? F_sum[bs_num] : 0) << endl;
    return 0;
}
/*
まとめ。
各日の価格を降順ソートして累積和取って、安くなる限りBSを購入していけば良い。
オーバーフローは勿論のこと、配列外参照にも気をつけましょう(1敗)
*/
