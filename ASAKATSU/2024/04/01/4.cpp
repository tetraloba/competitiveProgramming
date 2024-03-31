// 2024/04/01 07:41:19
// 2024/04/01 08:02:25 WA
#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
using namespace std;
int date(int m, int d) {
    // int mon_size[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int mon_size_sum[12] = {31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};
    int res = 0;
    if (2 <= m) {
        res += mon_size_sum[m - 2];
    }
    res += d;
    return res;
}
int main(){
    int N;
    cin >> N;
    bool hol[367] = {false};
    int sun = 1;
    while (sun <= 366) {
        hol[sun] = true;
        sun += 7;
    }
    int sat = 0;
    while (sat <= 366) {
        hol[sat] = true;
        sat += 7;
    }
    for (int i = 0; i < N; i++) {
        int m, d;
        scanf("%d/%d", &m, &d);
        // cin >> m >> d;
        int tgt = date(m, d);
        int loop_cnt = 0;
        while (hol[tgt] && loop_cnt <= 366) {
            /* これ無限ループ書いてよいのか？一年全部休日ってあり得る？ */
            tgt++;
            if (tgt == 367) tgt = 1; // 汚い…
            loop_cnt++;
        }
        hol[tgt] = true;
    }
    int cnt = 0, max = 0;
    int i = 1;
    int loop_cnt = 0;
    while (loop_cnt <= 800 || hol[i]) {
        // cout << hol[i] << ' ';
        if (hol[i]) {
            cnt++;
            max = max < cnt ? cnt : max;
        } else {
            cnt = 0;
        }
        i++;
        if (i == 367) i = 1;
        loop_cnt++;
    }
    cout << max << endl;
    return 0;
}
/*
僕が過去に書いたコードの中でもトップクラスに汚いかもしれない。(2024/04/01 08:10:54)
「2012 年の連休の最大日数」ってなんなん？
2013年にまたがる連休はどうするの？なんか問題の定義が意味わからない。(2024/04/01 08:17:13)
*/
