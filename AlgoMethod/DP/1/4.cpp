//2022/08/12 14:03:21
//2022/08/12 14:32:23 WA
//2022/08/12 15:18:58 AC.
#include <iostream>
#include <vector>
using namespace std;
long long int factorial(int N, int n){
    if (--n == 0) {
        return N ? N : 1;
    }
    return N * factorial(N - 1, n);
}
int cbn(int N, int n){
    if (N < n * 2) {
        n = N - n;
    }
    if (!n) {
        return 1;
    }
    return factorial(N, n) / factorial(n, n);
}
int cbn(int i, int j, int k){
    return cbn(i + j + k, i) * cbn(j + k, j);
}
int main(){
    int N;
    cin >> N;
    int ans = 0;
    int i = 0, j = 0;
    for (i = 0; i * 3 <= N; i++) {
        for (j = 0; i * 3 + j * 2 <= N; j++) {
            // cout << i << j << N-i*3-j*2 << endl;
            ans += cbn(i, j, N - i * 3 - j * 2);
        }
    }
    cout << ans << endl;
    return 0;
}
// 3変数の方程式として解く A + 2B + 3C = N → 並べ替え
// 2と3で解いて1への置き換えを考える → 3から1,2への置き換えもある。無理。
// 0 0 10
// 0 1 8
// 0 2 6
// 0 3 4
// 0 4 2
// 0 5 0
// 1 0 7
// 1 1 5
// 1 2 3
// 1 3 1
// 2 0 4
// 2 1 2
// 2 2 0
// 3 0 1