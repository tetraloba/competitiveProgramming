//2022/08/14 02:17:13
//2022/08/14 02:20:08 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    string S;
    cin >> S;
    int N = S.size();
    bool flag = true;
    for (int i = 0; i < N / 2; i++) {
        if (S[i] != S[N - 1 - i]) {
            flag = false;
        }
    }
    if (flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}