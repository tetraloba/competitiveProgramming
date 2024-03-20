// 2024/03/20 17:32:31
// 2024/03/20 17:41:59 14WA
// 2024/03/20 18:11:38 2WA
// 2024/03/20 18:39:19 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }
    long long sum = 0;
    for (int a : A) {
        sum += a;
    }
    int ave_s = sum / N; // 平均値(小数点以下切り捨て)
    long long min_diff_sum = INT64_MAX, ans;
    for (int ave = ave_s - 2; ave < ave_s + 3; ave++) { // 適当な範囲で探索(てきとう)
        long long diff_abs_sum = 0, diff_sum = 0;
        for (int a : A) {
            diff_abs_sum += abs(a - ave);
            diff_sum += a - ave;
        }
        diff_sum = abs(diff_sum);
        if (diff_sum < min_diff_sum) {
            min_diff_sum = diff_sum;
            ans = (diff_abs_sum - diff_sum) / 2;
        }
    }

    cout << ans << endl;
    return 0;
}
/*
操作を行っても平均値は変わらないので、各要素を平均値に寄せていくことを考えれば良いかな。(2024/03/20 17:33:52)
222888
554556
555555 までやるしかないよね。

222889
555556
平均値からの差分
-3,-3,-3,+3,+3,+4 -> +1
222899
555566
差分の絶対値の総和 - 差分の総和 で良かったりする？(2024/03/20 17:39:20)
割る2か。(2024/03/20 17:41:43)
うーん14WA(16AC)
222899
555566
-3,-3,-3,+3,+4,+4 -> +2
20
(20 - 2) / 2 = 9

22899 ave6
66666

22999 ave6.
66667
下が多い場合か？
22299 ave4.8
44466 (6)
45555 (8)
-2,-2,-2,+5,+5 -> +4
(16 - 4) / 2 = 6
-3,-3,-3,+4,+4 -> -1
(17 - (-1)) / 2 = 9
いや8か。
差分の絶対値かな。(てきとう)

222899
555566
ave6の時は
-4,-4,-4,+2,+3,+3 -> -4

22899
ave7だと
-5,-5,+1,+2,+2 -> -5

両方試しちゃうほうが早そう()
やっぱり2WAなんだが…()
*/
