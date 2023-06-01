//2023/04/04 20:54:34
//2023/04/04 21:02:28 AC.
#include <iostream>
#include <vector>
#include <string>
#include <regex>
using namespace std;
int main(){
    string S;
    cin >> S;
    regex reg(R"(^[A-Z][1-9]\d{5}[A-Z]$)");
    if (regex_match(S, reg)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}