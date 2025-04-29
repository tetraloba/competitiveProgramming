// 2025/04/29 07:30:14
// 2025/04/29 07:31:04 AC.
#include <iostream>
#include <vector>
using namespace std;
int f(int x) {
    return x * x + 2 * x + 3;
}
int main(){
    int t;
    cin >> t;
    cout << f(f(f(t) + t) + f(f(t))) << endl;
    return 0;
}
