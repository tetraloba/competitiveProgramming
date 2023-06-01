//2022/08/12 07:43:29
//2022/08/12 08:01:11 WA
//2022/08/12 08:20:39 AC.
#include <iostream>
#include <string>
#include <regex>
using namespace std;
int main(){
    string S;
    regex re(R"(A?KIHA?BA?RA?)");
    cin >> S;
    if (regex_match(S, re)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
// 正規表現わっかんないよおお