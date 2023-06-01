//2022/08/19 07:46:02
//
#include <iostream>
#include <vector>
using namespace std;
int main(){
    string S;
    cin >> S;
    int crt = 0, sum = 0, min = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '<') {
            crt++;
        } else {
            crt--;
        }
        cout << crt << ' ' << sum << ' ' << min << endl;
        sum += crt;
        if (crt < min) {
            min = crt;
        }
    }

    if (min < 0) {
        sum += (-min) * (S.size() + 1);
    }
    cout << sum << endl;
    return 0;
}