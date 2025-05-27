// 2023/11/04 21:00:08
// 2023/11/04 21:02:01 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    string S;
    cin >> N >> S;
    for (int i = 0; i < N - 1; i++) {
        if (S[i] == 'a' && S[i + 1] == 'b') {
            cout << "Yes" << endl;
            return 0;
        } else if (S[i] == 'b' && S[i + 1] == 'a') {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}