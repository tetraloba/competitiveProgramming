//2022/08/12 18:47:20
//2022/08/12 18:51:56 WA
//2022/08/12 18:55:33 AC.
#include <iostream>
#include <regex>
using namespace std;
int main(){
    string S;
    cin >> S;
    regex reg{R"(^([a-z]+-)*[a-z]+$)"};
    smatch m;
    bool search = regex_search(S, m, reg);
    if (search) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}