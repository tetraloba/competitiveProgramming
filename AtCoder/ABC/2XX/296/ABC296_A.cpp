// 2023/06/02 22:37:29
// 2023/06/02 22:38:56 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    string S;
    cin >> N >> S;
    for (int i = 0; i < N - 1; i++) {
        if (S[i] == S[i + 1]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}