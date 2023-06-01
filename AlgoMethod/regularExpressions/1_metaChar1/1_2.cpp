// 2022-08-12 18:25:21 AC.
#include <iostream>
#include <regex>
#include <string>
using namespace std;
int main(){
    string S;
    cin >> S;
    regex reg{R"(algo)"};
    smatch m;
    bool search = regex_search(S, m, reg);
    if (search) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}