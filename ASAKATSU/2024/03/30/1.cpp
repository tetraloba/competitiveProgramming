// 2024/03/30 07:30:09
// 2024/03/30 07:34:04 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, D;
    cin >> N >> D;
    vector<string> S(N);
    for (string &s : S) {
        cin >> s;
    }
    vector<bool> allo(D, true);
    for (int i = 0; i < D; i++) {
        for (int j = 0; j < N; j++) {
            if (S[j][i] == 'x') {
                allo[i] = false;
                break;
            }
        }
    }
    int max = 0, cnt = 0;
    for (int i = 0; i < D; i++) {
        if (allo[i]) {
            cnt++;
            if (max < cnt) {
                max = cnt;
            }
        } else {
            cnt = 0;
        }
    }
    cout << max << endl;
    return 0;
}
