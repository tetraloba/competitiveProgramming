//2022/08/12 18:31:13
//2022/08/12 18:34:48 AC.
#include <iostream>
#include <regex>
using namespace std;
int main(){
    string S;
    cin >> S;
    regex reg{R"(^a{1,5}b{10}c*$)"};
    if (regex_match(S, reg)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}