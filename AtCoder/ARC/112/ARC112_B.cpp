// 2025/04/28 10:08:12
// 2025/04/28 10:45:36 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    long long B, C;
    cin >> B >> C;
    pair<long long, long long> range1 = {-B - (C - 1) / 2, -(B - (C - 1) / 2)};
    pair<long long, long long> range2 = {B - C / 2, -(-B - (C - 2) / 2)};
    if (range2.first < range1.first) {
        swap(range1, range2);
    }
    long long ans;
    if (range2.second <= range1.second) {
        ans = range1.second - range1.first + 1;
    } else if (range2.first <= range1.second) {
        ans = (range1.second - range1.first + 1) + (range2.second - range2.first + 1) - (range1.second - range2.first + 1);
    } else {
        ans = (range1.second - range1.first + 1) + (range2.second - range2.first + 1);
    }
    cout << ans << endl;
    return 0;
}
/*
-1倍を何度もやっても意味ないから高々2回だよね。やらない、最初のみ、最後のみ、最初と最後(2025/04/28 10:11:03)
とりあえず(C - 2) / 2について考えるか。
100 50 のとき
24回 -1できる。
-124 ~ -100 ~ -76, 76 ~ 100 ~ 124
25回 -1して反転なしのパターンが75か。
-124 ~ -76, 75 ~ 124

100 51のときは？
-125 ~ -100 ~ -75, 75 ~ 100 ~ 124
25回 -1して1回反転があり得る。
-125 ~ -75, 75 ~ 124

あー Bの絶対値が小さくて重複する場合もあるのか…(2025/04/28 10:17:40)

-100 50 のとき
76 ~ 124, -125 ~ -76
-100 51 のとき
75 ~ 125, -125 ~ -76

すなわち
-B-(C-1)/2 ~ -(B-(C-1)/2), B-C/2 ~ -(-B-(C-2)/2)
の範囲の和ってことか。(2025/04/28 10:29:05)

Cが1や2のとき怪しいな。(2025/04/28 10:31:12)
100 1 のとき
-100 ~ -100, 100 ~ 100 大丈夫そう。
100 2 のとき
-100 ~ -100, 99 ~ 100 大丈夫そう。
*/
