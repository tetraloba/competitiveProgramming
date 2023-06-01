//2022/09/01 07:30:06
//2022/09/01 07:33:28 AC.
//ABC056_A - HonestOrDishonest
#include <iostream>
#include <vector>
using namespace std;
int main(){
    char a, b;
    cin >> a >> b;
    // cout << a << b;
    char ans;
    if (a == 'H') {
        ans = b == 'H' ? 'H' : 'D';
    } else {
        ans = b == 'H' ? 'D' : 'H';
    }
    cout << ans << endl;
    return 0;
}