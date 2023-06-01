//2022/08/13 11:16:07
//2022/08/13 11:18:18 AC.
#include <iostream>
#include <regex>
using namespace std;
int main(){
    string S;
    cin >> S;
    regex reg{R"([0-9])"};
    smatch m;
    bool search = regex_search(S, m, reg);
    if (search) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}