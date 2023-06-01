//2022/08/05 07:38:05
//2022/08/05 07:50:08 AC.
#include <iostream>
using namespace std;
int main(){
    int N;
    char S[100][10];
    cin >> N;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        cin >> S[i];
        for (int j = 0; j < 9; j++) {
            if (S[i][j] == 'x') {
                cnt++;
            } else if (S[i][j] == 'o' && (i == 0 || S[i - 1][j] != 'o')) {
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}