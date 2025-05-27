//2023/01/06 19:19:15
//2023/01/06 19:22:03 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    string S, T;
    cin >> S >> T;
    int i = 0;
    while (S[i]) {
        if (S[i] != T[i]) {
            cout << i + 1 << endl;
            return 0;
        }
        i++;
    }
    cout << i + 1 << endl;
    return 0;
}