//2022/08/14 02:33:15
//2022/08/14 02:38:23 AC.
#include <iostream>
#include <string>
using namespace std;
int main(){
    string S, T;
    cin >> S >> T;
    int N = S.size();
    int M = T.size();
    for (int i = 0; i < N; i++) {
        if (S[i] == T[0]) {
            bool flag = true;
            for (int j = 0; j < M; j++) {
                if (S[i + j] != T[j]) {
                    flag = false;
                }
            }
            if (flag) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}