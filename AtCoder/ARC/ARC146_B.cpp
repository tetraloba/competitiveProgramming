//2022/08/20 22:12:07
//2022/08/20 22:55:41 WA 知ってる。
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.rbegin(), A.rend()); //降順ソート
    long long sumK = 0;
    for (int i = 0; i < K; i++) {
        sumK += A[i];
    }
    // cout << "sumK:" << sumK << endl; //debug
    int x = 0;
    while ((long long)pow(2, x) * K - sumK <= M) { //*K忘れてた //左辺マイナスもあるのか…
        x++;
    }
    x -= 1; //Mで払い切れる限界pow(2, x);
    // cout << "target:" << pow(2, x) << endl; //debug
    long long ans = 0;
    while (0 <= x && 0 <= M) {
        // cout << "pow(2, x)=" << pow(2, x) << endl; //debug
        long long tmp = pow(2, x);
        if (tmp * K - sumK <= M) {
            M -= tmp * K - sumK;
            sumK = 0;
            // cout << "M:" << M << " sumK:" << sumK << endl; //debug
            ans += tmp;
        }
        x--;
    }
    cout << ans << endl;
    return 0;
}
// M 2^30はsigned intでギリか。
// K個をできる限り大きい2^Nにするのが最優先。
// ANDなので一つでも2^Nに満たないやつがあれば意味がない。この場合は下の桁で解を稼ぐ。100にできないなら11を目指す。
// 128, 256, 512
// X++していって
// Aの上位K個を2^XにできなくなるXを見つけて
// Aの上位K個を2^(X - 1)にする。
// 残りのMでK個を2^(X - 2)にできるか。for(X--)繰り返し
// M == 0またはX == 0で終了。端は未精査。
// 512 * 3 = 1536 , 1536 - 1040 = 496
// 端精査してないし通らないやろな。
// doubleの桁数どうなるんや、分からん…