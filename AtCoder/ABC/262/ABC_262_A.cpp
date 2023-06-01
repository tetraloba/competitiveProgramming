//2022/08/04 17:42:56
//2022/08/04 17:50:38 AC.
#include <iostream>
using namespace std;
int main(){
    int Y;
    cin >> Y;
    cout << Y + (6 - Y % 4) % 4 << '\n';
    return 0;
}
// 0 +2
// 1 +1
// 2 0
// 3 +3