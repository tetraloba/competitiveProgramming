//2022/08/12 18:42:48
//2022/08/12 18:44:49 AC.
#include <iostream>
#include <regex>
using namespace std;
int main(){
    string S;
    cin >> S;
    regex reg{R"(1\+1)"};
    smatch m;
    bool search = regex_search(S, m, reg);
    if (search) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}