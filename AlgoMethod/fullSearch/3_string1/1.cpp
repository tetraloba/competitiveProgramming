//2022/08/14 02:13:53
//2022/08/14 02:16:12 AC.
#include <iostream>
using namespace std;
int main(){
    string S;
    char c;
    cin >> S >> c;
    int N = S.size();
    bool flag = false;
    for (int i = 0; i < N; i++) {
        if (S[i] == c) {
            flag = true;
            break;
        }
    }
    if (flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}