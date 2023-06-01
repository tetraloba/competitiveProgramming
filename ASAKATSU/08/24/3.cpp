//2022/08/24 07:37:59
//2022/08/24 07:47:37 AC.
#include <iostream>
#include <vector>
using namespace std;
bool func(char c) {
    string S = "atcoder";
    for (int i = 0; i < 7; i++) {
        if (S[i] == c) {
            return true;
        }
    }
    return false;
}
int main(){
    string S, T;
    cin >> S >> T;
    int N = S.size();
    bool flag = true;
    for (int i = 0; i < N; i++) {
        if (S[i] != T[i]) {
            if (S[i] == '@') {
                if (!func(T[i])) {
                    flag = false;
                }
            } else if (T[i] == '@') {
                if (!func(S[i])) {
                    flag = false;
                }
            } else {
                flag = false;
            }
        }
    }
    cout << (flag ? "You can win" : "You will lose") << endl;
    return 0;
}