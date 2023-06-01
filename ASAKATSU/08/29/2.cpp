//2022/08/29 07:33:32
//2022/08/29 07:40:12 WA 拡張機能の不具合発見。
//2022/08/29 07:47:22 AC.
//ARC045_A - スペース高橋君
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
int main(){
    string S;
    getline(cin, S);
    stringstream ss{S};
    while (getline(ss, S, ' ')) {
        if (S[0] == 'L') {
            cout << '<';
        } else if (S[0] == 'R') {
            cout << '>';
        } else {
            cout << 'A';
        }
        if (!ss.eof()) {
            cout << ' ';
        } else {
            cout << endl;
            break;
        }
    }
    return 0;
}