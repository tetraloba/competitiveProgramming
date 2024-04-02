// 2024/04/03 07:30:08
// 2024/04/03 07:41:41 AC.
// ARC143_A - Three Integers
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<long long> A(3);
    cin >> A[0] >> A[1] >> A[2];
    sort(A.begin(), A.end());
    if (A[0] < A[2] - A[1] || A[1] < A[2] - A[0]) {
        cout << -1 << endl;
        return 0;
    }
    // cout << A[2] - A[1] + A[2] - A[0]
    cout << A[2] << endl;
    return 0;
}
/*
1増やすと考えるほうが分かりやすい？
1番大きいやつとそれ以外の差(2024/04/03 07:33:01)
結局一番大きい数と等しいってことないよね・・・(2024/04/03 07:38:09)
456
445x
355
344
333

426
ACで草(2024/04/03 07:41:59)
*/
