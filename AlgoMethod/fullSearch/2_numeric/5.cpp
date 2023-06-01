//2022/08/14 02:03:48
//2022/08/14 02:09:18 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        if (!(i % 3)) {
            cout << "Fizz";
        }
        if (!(i % 5)) {
            cout << "Buzz";
        }
        if (i % 3 && i % 5) {
            cout << i;
        }
        cout << endl;
    }
    return 0;
}