//2022/08/31 07:30:43
//2022/08/31 07:34:20 AC.
//ABC177_B - Substring
#include <iostream>
#include <vector>
using namespace std;
int main(){
    string S, T;
    cin >> S >> T;
    int N1 = S.size(), N2 = T.size();
    int max = 0;
    for (int i = 0; i < N1 - N2 + 1; i++) {
        int cnt = 0;
        for (int j = 0; j < N2; j++) {
            if (S[i + j] == T[j]) {
                cnt++;
            }
        }
        if (max < cnt) {
            max = cnt;
        }
    }
    cout << N2 - max << endl;
    return 0;
}