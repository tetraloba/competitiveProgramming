//2022/08/27 07:43:18
//2022/08/27 08:17:27 AC.
#include <iostream>
#include <vector>
using namespace std;
int func2(long long N){
    int cnt = 0;
    while (N) {
        N /= 10;
        cnt++;
    }
    return cnt;
}
long long func1(long long S, long long N, long long A, long long B, long long X){
    // cout << S << ' ' << N << ' ' << A << ' ' << B << ' ' << X << endl;
    if (S == N) {
        return S;
    }
    long long K = (S + N) / 2 + (S + N) % 2;
    // cout << K << ':' << ((long long)A * K + B * func2(K) <= X) << endl;
    // cout << "func(K)" << func2(K) << endl;
    if ((long long)A * K + B * func2(K) <= X) {
        return func1(K, N, A, B, X);
    }
    return func1(S, K - 1, A, B, X);
}
int main(){
    long long A, B, X;
    cin >> A >> B >> X;
    // long long  N = X / A;
    long long N = 1000000000;
    cout << func1(0, N, A, B, X) << endl;
    return 0;
}
// 2分探索書くか…