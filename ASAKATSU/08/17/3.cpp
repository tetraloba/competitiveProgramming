//2022/08/17 07:57:38
//途中で諦めて遊んでいた模様
//ABC184_C - Super Ryuma
#include <iostream>
#include <vector>
using namespace std;
int diff(int a, int b) {
    if (a < b) {
        return b - a;
    }
    return a - b;
}
int main(){
    int r1, c1, r2, c2, ans;
    cin >> r1 >> c1 >> r2 >> c2;
    if (r1 == r2 && c1 == c2) {
        ans = 0;
    } else if (r1 + c1 == r2 + c2 || r1 - c1 == r2 - c2 || diff(r1, c1) + diff(r2, c2) <= 3) {
        ans = 1;
    } else if ()
    cout <<  << endl;
    return 0;
}
//最大3手 遠い場所で、dx+dyが奇数の場所は斜め２回で移動できないので3手