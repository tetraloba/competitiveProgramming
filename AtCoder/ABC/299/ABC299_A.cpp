// 2023/11/03 11:59:40
// 2023/11/03 12:04:34 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    int phase = 0;
    int i = -1;
    while (++i < N) {
        if (S[i] == '|') {
            break;
        }
        if (S[i] == '*') {
            cout << "out" << endl;
            return 0;
        }
    }
    while (++i < N) {
        if (S[i] == '|') {
            cout << "out" << endl;
            return 0;
        }
        if (S[i] == '*') {
            break;
        }
    }
    cout << "in" << endl;
    return 0;
}