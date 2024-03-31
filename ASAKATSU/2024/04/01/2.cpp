// 2024/04/01 07:32:24
// 2024/04/01 07:37:23 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int A, B;
    cin >> A >> B;
    int ans = 0;
    for (int i = 0; i < A * 100; i++) {
        if (i * 8 / 100 == A && i * 10 / 100 == B) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
