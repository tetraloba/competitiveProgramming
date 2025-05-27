// 2025/03/03 18:53:16
// 2025/03/03 20:06:04 AC.
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;
long long A, B;
double F(long long x) {
    return A / sqrt(1 + x) + B * x;
}
int main() {
    cin >> A >> B;
    
    /* debug */
    // double dA = A, dB = B;
    // cerr << "dA: " << dA << '\t' << "dB: " << dB << endl;
    // const long long X_START = 2954170, X_END=2954191;
    // const long long X_START = 29240177375, X_END=29240177385;
    // 29240177381.128620
    // const long long X_START = 0, X_END=20;
    // cerr << "x\tF(x)\tF'(x)" << endl;
    // for (long long x = X_START; x < X_END; x++) {
    //     cerr << x << '\t' << dA / sqrt(1 + x) + dB * x << '\t' << -0.5 * dA * pow(1 + x, -1.5) + dB << endl;
    // }
    // cerr << fixed << setprecision(10) << pow((dB / 0.5 / dA), -2.0 / 3) - 1 << endl;

    long long x = pow((B / 0.5 / A), -2.0 / 3) - 1;
    x = max(0ll, x);
    cout << fixed << setprecision(10) << min(F(x), F(x + 1)) << endl;
    return 0;
}
/*
ニブタンできなくはないだろうが？(2025/03/03 18:55:13)
数学的に解けないのか？(2025/03/03 18:56:16)
min(A / sqrt(g + k) + B * k)でしょう？
あー微分か？(2025/03/03 19:02:28)
A * (g+x)^0.5^-1 + Bx
-1.5 * A * (g + x)^-2.5 + B = 0 を解くと
(g + x)^-2.5 = B / 1.5A
g + x = (B / 1.5A)^(-2/5)
x = (B / 1.5A)^(-2/5) - g
8,772,053,214,538.5976562500

間違えた(笑)
F(x) = A * (1 + x)^0.5^-1 + Bx
     = A * (1 + x)^(-0.5) + Bx
F'(x) = -0.5 * A * (1 + x)^(-1.5) + B
F'(x) = 0 を解くと
(1 + x)^-1.5 = B / (0.5 * A)
1 + x = (B / (0.5 * A))^(-2/3)
x = (B / 0.5 / A)^(-2/3) - 1

*/
