// 2024/04/14 19:52:35
// 2024/04/14 20:14:20 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    int L = 0, R = N - 1;
    while (true) {
        if (L + 1 == R) {
            cout << "! " << L + 1 << endl;
            return 0;
        }
        int tgt = (L + R) / 2;
        int tgt_value;
        cout << "? " << tgt + 1 << endl;
        cin >> tgt_value;
        if (tgt_value) {
            R = tgt;
        } else {
            L = tgt;
        }
    }
    return 0;
}
/*
意味が分からん。(2024/04/14 19:58:54)
左端の0と右端の1は保証される。
0?1...
なら1
まあ制約からしても二分探索だわな。
0???...???X???...???1
Xが0なら右半分が0???...???1となって同じことの繰り返し。(2024/04/14 20:00:40)
0 0 1
L=1, R=2

*/
