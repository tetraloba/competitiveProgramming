//2022/08/26 07:30:08
//2022/08/26 07:56:15 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int X, Y;
    cin >> X >> Y;
    for (int i = 0; i <= X; i++) {
        if (2 * i + 4 * (X - i) == Y) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
// A + B = X;
// 2 * A + 4 * B = Y;