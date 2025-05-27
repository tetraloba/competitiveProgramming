// 2024/07/19 23:01:00
// 2024/07/19 23:28:18 32WA
// 2024/07/19 23:35:44 13WA
// 2024/07/19 23:49:43 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<pair<int, int>> LR(N);
    for (auto &lr : LR) {
        cin >> lr.first >> lr.second;
    }

    long long l = 0, r = 0;
    long long adjust = 0;
    for (auto lr : LR) {
        l += lr.first;
        r += lr.second;
        // cerr << min << ' ' << max << endl; // debug
        if (0 < lr.first) {
            adjust -= lr.first;
        } else if (lr.second < 0) {
            adjust -= lr.second;
        }
    }
    if (0 < l || r < 0) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    for (auto lr : LR) {
        if (0 < lr.first) {
            long long d = min(max(adjust, (long long)0), (long long)lr.second - lr.first);
            cout << lr.first + d;
            adjust -= d;
            // cerr << 'a'; // debug
        } else if (lr.second < 0) {
            long long d = max(min(adjust, (long long)0), (long long)lr.first - lr.second);
            cout << lr.second + d;
            adjust -= d;
            // cerr << 'b'; // debug
        } else if (adjust < 0) {
            cout << max(adjust, (long long)lr.first);
            adjust -= max(adjust, (long long)lr.first);
            // cerr << 'c'; // debug
        } else {
            cout << min(adjust, (long long)lr.second);
            adjust -= min(adjust, (long long)lr.second);
            // cerr << 'd'; // debug
        }
        cout << ' ';
    }
    cout << endl;
    return 0;
}
/*
判定は簡単。範囲を動かしていくだけ。
問題は分配方法。
原則0にして、左正と右負の負債を分配していくと考えるか？(2024/07/19 23:12:16)
0
-54
2
0
87
0
負債45
*/
/*
解説を読んで。
あー原則0じゃなくて原則Lにしておけばよかったのか。
adjustなんて面倒なことしなくて済んだのね。
アルコールのせいということにしておこう。
*/
