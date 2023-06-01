//2022/08/13 11:20:43
//2022/08/13 11:22:51 AC.
#include <iostream>
#include <vector>
#include <regex>
using namespace std;
int main(){
    string S;
    cin >> S;
    regex reg{R"(\d\d\d)"};
    smatch m;
    bool search = regex_search(S, m, reg);
    if (search) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}