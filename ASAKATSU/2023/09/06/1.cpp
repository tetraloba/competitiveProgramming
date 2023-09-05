// 2023/09/06 07:30:06
// 2023/09/06 07:31:47 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    string S;
    cin >> S;
    for (char c : S) {
        cout << (char)(c + ('A' - 'a'));
    }
    cout << endl;
    return 0;
}