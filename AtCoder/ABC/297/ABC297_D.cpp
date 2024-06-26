// 2024/04/14 20:15:20
// 2024/04/14 20:31:37 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    long long A, B;
    cin >> A >> B;
    if (B < A) {
        swap(A, B);
    }
    long long ans = 0;
    while (A != B) {
        ans += B / A;
        B = B % A;
        if (!B) {
            cout << ans - 1 << endl;
            return 0;
        }
        swap(A, B);
    }
    cout << ans << endl;
    return 0;
}
/*
差に注目してみる(2024/04/14 20:16:35)
3 8 (5)
3 5 (2)
3 2 (1)
1 2 (1)
1 1 (0)
|A - (B - A)| = |2A - B|
現在の差と小さい方の差が次の差(2024/04/14 20:19:46)

1 8
1 7
1 6
1 5
...
が長くなるパターン

4 9
4 5
4 1
まあ小さい方で剰余取るのが多少早いか。(2024/04/14 20:24:03)
それだけで行けたりする？時間計算できないぞ。

長くなるのはフィボナッチ数列の時？(2024/04/14 20:27:52)
13 21
13 8
5 8
5 3
2 3
2 1
1 1
2回で2倍以上には増えるから、2^64でも128回くらいでいけるのかしら？(2024/04/14 20:29:25)
*/
