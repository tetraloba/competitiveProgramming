//2022/08/12 18:26:37
//2022/08/12 18:29:36 AC.
#include <iostream>
#include <vector>
#include <regex>
using namespace std;
int main(){
    string S;
    cin >> S;
    regex reg{R"(^metho+d$)"};
    smatch m;
    bool search = regex_search(S, m, reg);
    if (search) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}