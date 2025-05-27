//2022/08/21 21:00:09
//2022/08/21 21:03:35 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int X, Y, N;
    cin >> X >> Y >> N;
    cout <<  ( Y < X * 3 ? N / 3 * Y + N % 3 * X : N * X) << endl;
    return 0;
}