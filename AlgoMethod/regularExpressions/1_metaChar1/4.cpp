//2022/08/12 18:35:19
//2022/08/12 18:39:08 AC.
#include <iostream>
#include <regex>
using namespace std;
int main(){
    string S;
    cin >> S;
    regex reg{R"(cat|dog)"};
    smatch m;
    bool search = regex_search(S, m, reg);
    if (search) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}