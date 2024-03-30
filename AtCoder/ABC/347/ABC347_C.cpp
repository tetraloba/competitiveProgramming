// 2024/03/30 21:04:10
// 2024/03/30 21:24:25 TLE, MLE, RE
// 2024/03/30 22:07:06 10WA
// 2024/03/30 22:14:47 AC.
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> D(N);
    for (int &d : D) {
        cin >> d;
        d--;
    }
    set<int> sched_day; // 各曜日の予定の数(1日目の時)
    for (int i = 0; i < N; i++) {
        sched_day.insert(D[i] % (A + B));
    }
    // /* debug */
    // cout << "sche_cnt:";
    // for (auto [k, v] : sche_cnt) {
    //     cout << k << '-' << v << ' ';
    // }
    // cout << endl;

    auto itr = sched_day.begin();
    int pre = *itr;
    itr++;
    while (itr != sched_day.end()) {
        if (*itr - pre > B) { // 予定間にB以上の隙間が有ればそこに平日を打ち込めば良い
            cout << "Yes" << endl;
            return 0;
        }
        pre = *itr;
        itr++;
    }
    /* 最後尾の曜日から 最前の曜日まで の距離 */
    if ((long long)*sched_day.begin() + A + B - *sched_day.rbegin() > B) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}
/*
Nが緩いからNで探索か。
曜日を決めて、それがAに収まれば良い
intは4byte
2*10^9確保すると8*10^9Byte
8GBでMLEか。なるほど。(2024/03/30 21:46:37)
mapで管理すればよいよね。(2024/03/30 21:47:00)

あーA+Bは間に合わないか。
っていうかあれだ。入っている場所同士の距離だけを計算すればいいのか。完全に理解した。(2024/03/30 21:53:47)
3 5 (7)
6
5 6 7 1 2 3

1 (7)

*/
