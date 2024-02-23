// 2024/02/23 23:00:24
// 2024/02/24 01:09:33 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;

    /* 各位の和が3になる整数で小さいものからN番目を求める問題 */
    int n1, n2, n3; // 210なら3,3,2 111なら3,2,1 1002なら4,1,1
    int len = 2; // 桁数
    while (true) {
        int tmp  = len * (len - 1) / 2; // len C 2
        if (N <= tmp) {
            break;
        }
        N -= tmp;
        len++;
    }
    n1 = len - 1;
    // n1 桁のN番目
    len = 1; // n2とn3のみでの桁数
    while (true) {
        int tmp = len; // len C 1
        if (N <= tmp) {
            break;
        }
        N -= tmp;
        len++;
    }
    n2 = len;
    n3 = N;

    // cout << n1 << ' ' << n2 << ' ' << n3 << endl; // debug

    int v = 1;
    for (int i = n1; 1 <= i; i--) {
        if (i == n2) {
            v++;
        }
        if (i == n3) {
            v++;
        }
        cout << v;
    }
    cout << endl;
    return 0;
}
