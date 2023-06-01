//2022/08/26 07:32:59
//2022/08/26 07:39:39 AC.
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    string S;
    cin >> S;
    int N = S.size();
    bool flag = false;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'i' || S[i] == 'I') {
            for (; i < N; i++) {
                if (S[i] == 'c' || S[i] == 'C') {
                    for (; i < N; i++) {
                        if (S[i] == 't' || S[i] == 'T') {
                            flag = true;
                            break;
                        }
                    }
                }
            }
        }
    }
    cout << (flag ? "YES" : "NO") << endl;
    return 0;
}