// 2023/10/06 19:32:06
// 
#include <iostream>
#include <vector>
using namespace std;
int abs(int a, int b){
    return a < b ? b - a : a - b;
}
int main(){
    int d, x, y;
    cin >> d >> x >> y;
    cout << (abs(x, 0) + abs(y, 0) <= d ? "Yes" : "No") << endl;
    return 0;
}
