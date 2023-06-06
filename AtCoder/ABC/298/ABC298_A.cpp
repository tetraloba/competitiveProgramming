// 2023/06/06 12:20:15
// 2023/06/06 12:24:51 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    string S;
    cin >> N >> S;
    bool f1 = false, f2 = true;
    for (char c : S) {
        if (c == 'o') {
            f1 = true;
        } else if (c == 'x') {
            f2 = false;
        }
    }
    cout << ((f1 && f2) ? "Yes" : "No") << endl;
    return 0;
}