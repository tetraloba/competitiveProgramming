//2023/04/04 21:09:01
//2023/04/04 21:11:15 AC.
#include <iostream>
#include <string>
using namespace std;
int main(){
    string S;
    cin >> S;
    int N = S.length();
    for (int i = 0; i < N; i++) {
        if ('A' <= S[i] && S[i] <= 'Z') {
            cout << i + 1 << endl;
            return 0;
        }
    }
}