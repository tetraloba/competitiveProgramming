//2023/04/05 22:47:31
//2023/04/05 22:56:44 AC.
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    string S;
    cin >> S;
    transform(S.cbegin(), S.cend(), S.begin(), ::toupper);
    cout << S << endl;
    return 0;
}