//2022/08/20 19:22:42
//2022/08/20 19:45:51 WA 2WAなので例外処理が甘いんだろうな → 違うわ。いつものだわ。
//2022/08/20 19:58:35 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, A, B;
    cin >> N >> A >> B;
    if (B < A || (N == 1 && A != B)) {
        cout << 0 << endl;
    } else {
        cout << (long long)(B - A) * (N - 2) + 1 << endl;
    }
    return 0;
}
// A == B ならば Nの値に関わらず ans = 1
// B < A ならば Nの値に関わらず ans = 0
// N == 1 ならば A == B に限り ans = 1 → 1と統合
// N == 1 で A != B ならば ans = 0
// N == 2 ならば A + Bのみなので ans = 1
// ここまで例外処理↑
// 3 <= N ならば AとBの間によって変わる
// A < B ならば Nによって変わる