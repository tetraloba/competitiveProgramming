//2022/10/06 09:03:07
//2022/10/06 09:08:19 AC.
#include <iostream>
#include <string>
using namespace std;
int main(){
    string Days[5] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    string S;
    cin >> S;
    for (int i = 0; i < 5; i++) {
        if (S == Days[i]) {
            cout << 5 - i << endl;
            break;
        }
    }
    return 0;
}