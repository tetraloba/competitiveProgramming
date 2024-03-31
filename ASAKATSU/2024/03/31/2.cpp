// 2024/03/31 07:47:10
// 2024/03/31 08:07:24 AC.
// ARC113_B - A^B^C https://atcoder.jp/contests/arc113/tasks/arc113_b
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int A, B, C;
    cin >> A >> B >> C;
    vector<vector<int>> num = {{0}, {1}, {2, 4, 8, 6}, {3, 9, 7, 1}, {4, 6}, {5}, {6}, {7, 9, 3, 1}, {8, 4, 2, 6}, {9, 1}};
    A %= 10;
    B %= num[A].size();
    B = num[B][(C - 1) % num[B].size()];
    A = num[A][(B - 1) % num[A].size()];
    // cout << A << ' ' << B << ' ' << C << endl; // debug
    cout << A << endl;
    return 0;
}
/*
9 % 5 = 4
81 % 5 = 1
729 % 5 = 4
...

4 % 5
16 % 5
...
と同じか。(2024/03/31 08:02:15)
*/
