//2022/08/15 07:34:43
//2022/08/15 07:45:09 AC.
//ABC079_C
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int A, B, C, D;
    string S;
    cin >> S;
    A = S[0] - '0';
    B = S[1] - '0';
    C = S[2] - '0';
    D = S[3] - '0';
    int flag = 0;
    for (int i = 0; i < 8; i++) {
        if (A + B * (i % 2 ? 1 : -1) + C * (i / 2 % 2 ? 1 : -1) + D * (i / 4 % 2 ? 1 : -1) == 7) {
            cout << A << (i % 2 ? '+' : '-') << B << (i / 2 % 2 ? '+' : '-') << C << (i / 4 % 2 ? '+' : '-') << D << "=7" << endl;
            break;
        } 
    }
    return 0;
}