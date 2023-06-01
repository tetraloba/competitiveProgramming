//2022/09/05 07:38:12
//2022/09/05 08:35:51 AC. Sample2において、7行目intのときA入力時点でオーバーフローする謎。
//ARC145_B - AB Game
#include <iostream>
#include <vector>
using namespace std;
int main(){
    long long N, A, B;
    cin >> N >> A >> B;
    long long ans;
    if (N < A) {
        ans = 0;
    } else if (A <= B) { // A <= N, A <= B
        ans = N - A + 1;
    } else { //B < A <= N
        // ans = B * ((N - B) / A) + (N - B) % A;
        ans = B * ((N - B) / A) + (N % A < B ? N % A + 1 : 0);
    }
    cout << ans << endl;
    return 0;
}
//考察ゲーだが、普通に剰余じゃだめ・・・？
//5 3 2
//どうせ倍数で取れるなら
//10^18 数え上げでは間に合わない、と。
//A <= BならAの勝ち。
//B < Aについて、
//A < n && n % A < B ？
//1 <= n < A はAの負け。 A - 1
//A <= n < A + B はAの勝ち。 B
//A+B <= n < 2A はAの負け A - B
//2A <= n < 2A + B はAの勝ち B
//2A+B <= n < 3A はAの負け A - B
//N / A, (N - B) / A
// 1 <= n < 2, B
// 2 <= n < 3, A
// 3 <= n < 4, B
// 4 <= n < 5, A
// N % A < B?
// (N - B) % A
//10, 5, 3
//1~4 B
//5, 6, 7 A
//8, 9 B
//10 A
//N % A < B ならば N - A * (N / A) を足す