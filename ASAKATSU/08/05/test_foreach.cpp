//2022/08/05 09:24:34
//
#include <iostream>
using namespace std;
int main(){
    // int dir[2][4] = {{0, 0, -1, 1}, {-1, 1, 0, 0}};
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    for (int x[2] : dir) {
        cout << x[0] << ':' << x[1] << endl;
    }
    // for (int x : dir[0]) {
    //     cout << x << endl;
    // }
    return 0;
}