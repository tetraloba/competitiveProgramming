#include <iostream>
using namespace std;
int main(){
    char S[101];
    cin >> S;
    if (S[0] == 'm' && S[1] == 'e' && S[2] == 't' && S[3] == 'h' && S[4] == 'o') {
        int i = 5;
        while (S[i] == 'o') {
            i++;
        }
        if (S[i] == 'd' && S[i + 1] == '\0') {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}