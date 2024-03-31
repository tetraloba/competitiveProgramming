// 2024/04/01 07:37:40
// 2024/04/01 07:40:52 WA
#include <iostream>
#include <vector>
using namespace std;
int main(){
    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    cout << abs((x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3)) / 2 << endl;
    return 0;
}
