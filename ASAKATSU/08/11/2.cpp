//2022/08/11 07:33:36
// 2022/08/11 07:57:24 AC. ??????????????
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int a, b, d;
    cin >> a >> b >> d;
    cout << "M_PI = " << M_PI << endl;
    cout << fixed << a * cos(M_PI * d / 360) - b * sin(M_PI * d / 360) << ' ' << b * cos(M_PI * d / 360) + a * sin(M_PI * d / 360) << endl;
    // cout << fixed << a * cos(PI * 2 * d / 360) - b * sin(PI * 2 * d / 360) << ' ' << b * cos(PI * 2 * d / 360) + a * sin(PI * 2 * d / 360) << endl;
    return 0;
}