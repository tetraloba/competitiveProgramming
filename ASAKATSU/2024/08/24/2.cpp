// 2024/08/24 07:39:52
// 2024/08/24 07:46:13 りだつ
// 2024/08/24 07:47:56 ふっき
// 2024/08/24 07:57:05 AC.
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
        // cerr << A << ' ' << B << endl;
        if (B % A == 0) {
            ans += B / A - 1;
            break;
        }
        ans += B / A;
        long long tmp = A;
        A = B % A;
        B = tmp;
    }
    cout << ans << endl;
    return 0;
}
/*
大きい方から小さい方を引く
剰余
10 3
1 3
時間かかるのはどういう時？(2024/08/24 07:42:04)
/の結果が1のとき
1 2
3 2
3 5
8 5
8 13
フィボナッチ。(2024/08/24 07:43:23)
*/
