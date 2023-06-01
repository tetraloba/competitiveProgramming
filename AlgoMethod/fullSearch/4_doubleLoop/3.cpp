//2022/08/15 13:15:03
//2022/08/15 13:25:14 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int L, R;
    cin >> L >> R;
    int cnt = 0;
    for (int i = L; i <= R; i++) {
        string S = to_string(i);
        int flag = true;
        for (int j = 0; j < S.size(); j++) {
            // cout << S[j] << ':' << S[S.size() - j - 1] << endl;
            if (S[j] != S[S.size() - j - 1]) {
                flag = false;
            }
        }
        if (flag) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}