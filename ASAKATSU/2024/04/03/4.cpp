// 2024/04/03 08:18:46
// 2024/04/03 08:31:36 AC.
// ABC197_D - Opposite
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#define PI 3.1415926535897932384626
using namespace std;
int main(){
    int N;
    cin >> N;
    int x0, y0, xo, yo;
    cin >> x0 >> y0 >> xo >> yo;
    double orgx = (x0 + xo) / 2.0, orgy = (y0 + yo) / 2.0;
    double theta = 2 * PI / N;
    double x1 = (x0 - orgx) * cos(theta) - (y0 - orgy) * sin(theta) + orgx;
    double y1 = (x0 - orgx) * sin(theta) + (y0 - orgy) * cos(theta) + orgy;
    cout << setprecision(10) << x1 << ' ' << y1 << endl;
    return 0;
}
/*
対角線が与えられて、円周上？

*/
