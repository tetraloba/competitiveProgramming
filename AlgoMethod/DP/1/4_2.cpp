// これは失敗作
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
int func123(int N, int i, int j, int k){
    int sum = 0;
    if (1 <= N) {
        sum += func123(N - 1, i, j, k + 1);
    }
    if (2 <= N) {
        sum += func123(N - 2, i, j + 1, k);
    }
    if (3 <= N) {
        sum += func123(N - 3, i + 1, j, k);
    }
    if (!N) {
        cout << i << ' ' << j << ' ' << k << ' ' << cbn(i, j, k) << endl;
        sum += cbn(i, j, k);
    }
    return sum;
}
int main(){
    int N;
    cin >> N;
    cout << func123(N, 0, 0, 0) << endl;
    return 0;
}
// 再帰をふんだんに使って書いてみるか。
// 3 0 0 0
// 2 0 0 1
// 1 0 0 2
// 0 0 0 3 -> cbn(003) = 1
// 0 0 1 1 -> cbn(011) = 2
// 0 1 0 0 -> cbn(100) = 1