//2022/08/22 07:31:40
//2022/08/22 07:36:45 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    string S;
    cin >> S;
    int N = S.size();
    bool flag = true;
    for (int i = 0; i < N; i++) {
        if (S[i] != S[N - i - 1]) {
            flag = false;
        }
    }
    if (flag) {
        for (int i = 0; i < (N - 1) / 2; i++) {
            if (S[i] != S[(N - 1) / 2 - i - 1]) {
                flag = false;
            }
        }
        for (int i = (N + 3) / 2 - 1; i < N; i++) {
            if (S[i] != S[N - i - 1]) {
                flag = false;
            }
        }
    }
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}