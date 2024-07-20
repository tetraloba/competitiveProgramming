// 2024/07/20 15:33:20
// 2024/07/20 16:28:07 AC.
#include <iostream>
#include <vector>
#define NUM 998244353
using namespace std;
int main(){
    long long N, M;
    cin >> N >> M;

    long long ans = 0;
    long long P = 1;
    while (M) {
        if (M % 2) {
            long long Q = (N - P) / (P * 2);
            // cerr << Q << ',' << (Q * P % NUM + max((long long)0, min(P, N - (P + Q * (P * 2)) + 1)) % NUM) % NUM << endl; // debug
            ans += (Q * P % NUM + max((long long)0, min(P, N - (P + Q * (P * 2)) + 1)) % NUM) % NUM;
            ans %= NUM;
        }
        M /= 2;
        P *= 2;
    }
    cout << ans << endl;
    return 0;
}
/*
Mの2進数表記で1である各位について、0~Nまでに何回1が立つかを求めていけば良い。(2024/07/20 15:39:38)
その位が1の時、他の位が取れる組み合わせの数を求めると言っても良い。(2024/07/20 15:41:45)
1の位が1
1, 3, 5, 7, 9, 11, ...
2の位が1
2,3, 6,7, 10,11, 14,15, 18,19, 22,23, ...
4の位が1
4,5,6,7, 12,13,14,15, 20,21,22,23, ...

Pの位が1
    塊の数Q = (N - P ) / (P * 2)
    Q * P + (N - (P + Q * (P * 2)) + 1)
      塊  +   端数
    ただし端数はPを超えず、負にもならない。(0~P)
*/
