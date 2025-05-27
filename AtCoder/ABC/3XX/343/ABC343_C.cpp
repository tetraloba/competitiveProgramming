// 2024/03/10 17:57:50
// 2024/03/10 18:15:02 WA
// 2024/03/10 18:21:20 AC.
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    long long N;
    cin >> N;

    int lim = pow(N, (double)1/3);
    lim++;
    if (N < (long long)lim * lim * lim) {
        lim--;
    }
    string ans;
    for (int i = lim; 1 <= i; i--) {
        string str = to_string((long long)i * i * i);
        int l = 0, r = str.size() - 1;
        bool flag = true;
        while (l < r) {
            if (str[l++] != str[r--]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << str << endl;
            return 0;
        }
    }
    return 0;
}
/*
343
3443
*/
/*
3乗根の計算で浮動小数点数の誤差が出る。一旦インクリメントして大きすぎるならデクリメントすることで微調整した。
後は3乗根を大きい方から順に試して行って3乗したものが回文なら出力して終了。
*/
