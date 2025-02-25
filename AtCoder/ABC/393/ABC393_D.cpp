// 2025/02/25 13:30:59
// 2025/02/25 13:39:37 15WA
// 2025/02/25 13:57:06 muri
// 2025/02/25 14:13:44 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    int l = 0, r = N - 1, l_size = 0, r_size = 0;
    long long ans = 0;
    while (l <= r) {
        if (l_size < r_size) {
            if (S[l] == '1') {
                l_size++;
            } else {
                ans += l_size;
            }
            l++;
        } else {
            if (S[r] == '1') {
                r_size++;
            } else {
                ans += r_size;
            }
            r--;
        }
    }
    cout << ans << endl;
    return 0;
}
/*
端のやつから寄せていくことを考えれば良いかしら。(2025/02/25 13:33:10)
1100100000011
塊の小さい方がすり寄っていく感じ？(2025/02/25 13:34:37)
10101010101
1110111
*/
