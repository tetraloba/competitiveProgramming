// 2024/07/05 09:02:14
// 2024/07/05 10:17:07 AC.
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<pair<int, int>> LR(N);
    for (auto &lr : LR) {
        cin >> lr.first >> lr.second;
    }

    sort(LR.begin(), LR.end());

    long long ans = 0;
    long long dup_num = 0;
    priority_queue<int> pque;
    for (auto lr : LR) {
        while (!pque.empty() && -pque.top() < lr.first) {
            dup_num--;
            pque.pop();
        }
        ans += dup_num;
        pque.push(-lr.second);
        dup_num++;
    }

    cout << ans << endl;

    return 0;
}
/*
組み合わせ全探索だとNC2で間に合わない
最小値と最大値でimos法していけば重なっている数は求められるが…？(2024/07/05  9:05)
012210

011100
001110

011000
001100
000110

確定しないよなあ…(2024/07/05 09:07:55)
順番に見ていって、自分より前のやつに重なるやつが何個有るかをO(1)乃至O(logN)で求められれば良い。(2024/07/05 09:12:04)
自分の範囲内で、減った数と増えた数と最小値の和？(2024/07/05 09:32:02)
00111000
01110000
11111111

00110000
01111000
11111111

00001000
01000000
00110000
11111111
*/
