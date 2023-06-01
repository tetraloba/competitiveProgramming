//2022/08/16 11:13:13
//2022/08/16 11:14:43 AC.
#include <iostream>
using namespace std;
int main(){
    string S = "01001";
    int N = S.size();
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '1') {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}