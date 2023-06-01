//2022/08/23 07:39:56
//2022/08/23 08:00:07 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int min_i = 0;
    for (int i = 1; i < N; i++) {
        if (A[i] < A[min_i]) {
            min_i = i;
        }
    }
    int min_i2 = min_i;
    while (1) {
        for (int i = 0; i < N; i++) {
            if (i != min_i) {
                A[i] %= A[min_i];
                if (A[i]) { //A[i]<A[min_i]は自明
                    min_i2 = i;
                }
            }
        }
        if (min_i == min_i2) {
            break;
        }
        min_i = min_i2;
    }
    cout << A[min_i] << endl;
    return 0;
}
//考察ゲーやなあ…
//引き算と言うより割り算か？
//組み合わせ全探索で剰余の最小値？違うな…sample2...
//剰余同士の剰余もとれるってことか・・・
//最小値で剰余を取った後、剰余が先の最小値を下回るならそれでさらに剰余をとる・・・
//これで漏れないのか？？
//さきに最小値で剰余を取らないほうが良い場合
//1~6, 7, 8とか？ 8 % 7 で1作ったほうが良さそうだけど、1~6でも同じ結果が保証される？
//10 98 99
//10 98 1
//0 0 1
//10 98 99
//10 8 9
//2 8 1
//あーそうか、A < B < B + p なら (B % A, (B + p) % A) = (C, C + p)になりそうだな。MOD分からんけど。
//入力に0はない