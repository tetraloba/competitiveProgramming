#include <iostream>
using namespace std;
int main(){
    int a, b;
    cin >> a >> b;
    cout << a / b << ' ' << a % b << ' ' << (double)a / b << '\n'; //これだと小数点以下の桁数不足。 fixedとかマニピュレータとか調べてどうぞ。
    return 0;
}