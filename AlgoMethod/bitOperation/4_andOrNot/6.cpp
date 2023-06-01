//2022/08/18 19:06:27
//2022/08/18 19:06:54 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int A, i;
    cin >> A >> i;
    cout << (A | 1 << i) << endl;
    return 0;
}