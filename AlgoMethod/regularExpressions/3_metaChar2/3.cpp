//2022/08/13 11:23:43
//2022/08/13 11:25:57 AC.
#include <iostream>
#include <regex>
using namespace std;
int main(){
    string S;
    cin >> S;
    regex reg{R"(^\d{3}-\d{4}$)"};
    smatch m;
    bool search = regex_search(S, m, reg);
    if (search) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}