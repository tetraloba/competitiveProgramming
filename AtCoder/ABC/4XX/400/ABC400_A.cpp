// 2025/04/05 21:00:10
// 2025/04/05 21:03:42 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int A;
    cin >> A;
    if (400 % A) {
        cout << -1 << endl;
    } else {
        cout << 400 / A << endl;
    }
    return 0;
}
