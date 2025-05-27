// 2024/04/13 21:03:18
// 2024/04/13 21:13:08 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    string S, T;
    cin >> S >> T;
    transform(T.begin(), T.end(), T.begin(), ::tolower);
    int num = 0;
    for (char s : S) {
        if (s == T[num]) {
            num++;
        }
        if (num == 3) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    if (num < 2) {
        cout << "No" << endl;
        return 0;
    }
    if (T[num] == 'x') {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}
