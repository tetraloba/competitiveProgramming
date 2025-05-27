// 2024/04/13 21:13:21
// 2024/04/13 21:54:46 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    long long L, R;
    cin >> L >> R;
    vector<pair<long long, long long>> ans;
    if (L == 0) {
        long long tmp_R = 1;
        while (tmp_R <= R) {
            tmp_R *= 2;
        }
        tmp_R /= 2;
        ans.push_back({L, tmp_R});
        L = tmp_R;
    }
    while (true) {
        if (R <= L) {
            break;
        }
        long long tmp_L = L;
        long long i = 1;
        while (tmp_L % 2 == 0) {
            tmp_L /= 2;
            i *= 2;
            // cout << tmp_L << ' '; // debug
        }
        // cout << tmp_L << ':' << i << endl; // debug
        long long tmp_R = (tmp_L + 1) * i;
        // cout << "tmp_R: " << tmp_R << endl; // debug
        while (R < tmp_R) {
            tmp_L *= 2;
            i /= 2;
            tmp_R = (tmp_L + 1) * i;
        }
        ans.push_back({L, tmp_R});
        // cout << L << ' ' << tmp_R << endl; // debug
        L = tmp_R;
    }
    cout << ans.size() << endl;
    for (auto a : ans) {
        cout << a.first << ' ' << a.second << endl;
    }
    return 0;
}
/*
2^i*(j), 2^i*(j+1) って何やねん…

i=0
0,1
1,2
2,3
3,4 <- 3始まりはこれのみ
4,5

i=1
0,2
2,4
4,6
6,8

i=2
0,4
4,8 <- 4始まりはこれが最大
8,12
12,16
16,20

i=3
0,8
8,16


貪欲法で良いのかね？(2024/04/13 21:26:11)

3940649673945088 = 2^12 * 962072674303
(962072674303 + 1) * (2^12) までってことやね。

*/
