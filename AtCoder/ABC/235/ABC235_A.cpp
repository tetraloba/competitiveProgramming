//2022/08/21 20:52:42
//2022/08/21 20:54:47 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int abc, a, b, c;
    cin >> abc;
    a = abc / 100;
    b = abc / 10 % 10;
    c = abc % 10;
    cout << (a + b + c) * 111 << endl;
    return 0;
}