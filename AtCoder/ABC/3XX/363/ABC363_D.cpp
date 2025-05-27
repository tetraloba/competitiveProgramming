// 2025/03/02 10:39:43
// 2025/03/02 11:43:40 8WA
// 2025/03/02 11:53:23 AC.
#include <iostream>
#include <vector>
using namespace std;

/* N番目はnum桁のno番目 */
pair<int, long long> num_no(long long N) {
    long long remain = N;
    if (remain == 1) {
        return {0, 1};
    }
    remain -= 1;
    int i = 1;
    long long num_of_i = 9;
    while (i < INT32_MAX) {
        if (remain <= num_of_i) {
            return {i, remain};
        }
        remain -= num_of_i;
        if (i % 2 == 0) {
            num_of_i *= 10;
        }
        i++;
    }
    return {-1, -1};
}
/* num桁no番目の回分数 */
vector<int> palindr(int num, long long no) {
    if (num == 0) {
        return {0};
    }
    vector<int> ans(num, -1);
    if (num == 1) {
        no--;
    }
    no--;
    for (int i = num / 2 - 1 + num % 2; 0 <= i; i--) {
        ans[i] = no % 10;
        ans[num - 1 - i] = no % 10;
        no /= 10;
    }
    ans[0] += 1;
    ans[num - 1] += 1;
    return ans;
}
int main() {
    long long N;
    cin >> N;

    auto [num, no] = num_no(N);
    // cerr << num << "桁の" << no << "番目" << endl; // debug
    vector<int> ans = palindr(num, no);
    for (int i : ans) {
        cout << i;
    }
    cout << endl;
    return 0;
}
/*
桁ごとの回分数の数を求めていくしか無いな。
(1) = 10
(2) = (1)
(3) = (1) * (2)
(4) = (2) * (2) ?
(5) = (2) * (3)
(6) = (2) * (4)
(7) = (3) * (4)
(8) = (2) * (6) = (4) * (4)
(9) = (4) * (5)
(10) = (2) * (8) = (4) * (6)

ある桁数のM番目は？(2025/03/02 10:46:14)
000
010
...
090
101
半分(桁 / 2 + 1)だけ見れば良いのか。
3桁なら
00
01
...
09
10
...
19
20
...
29
...
*/
