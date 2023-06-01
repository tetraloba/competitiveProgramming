//2022/08/13 21:01:26
//2022/08/13 21:08:11 WA
//2022/08/13 21:11:10 AC.
#include <iostream>
#include <vector>
using namespace std;
int diff(int A, int B){
    if (A < B) {
        return B - A;
    }
    return A - B;
}
int main(){
    int R, C;
    cin >> R >> C;
    bool flag = false; //0:black, 1:white
    if (max(diff(8, R), diff(8, C)) % 2) {
        flag = false;
    } else {
        flag = true;
    }
    if (flag) {
        cout << "white" << endl;
    } else {
        cout << "black" << endl;
    }
    return 0;
}
//max(8-R, 8-C)%2