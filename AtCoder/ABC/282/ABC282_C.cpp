// 2024/02/21 12:37:14
// 2024/02/21 12:39:41 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    bool inside = false;
    for (int i = 0; i < N; i++) {
        if (!inside && S[i] == ',') {
            S[i] = '.';
        } else if (S[i] == '"') {
            inside = !inside;
        }
    }
    cout << S << endl;
    return 0;
}