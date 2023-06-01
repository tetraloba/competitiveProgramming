//2022/08/15 13:29:58
//2022/08/15 13:35:00 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        bool flag = true;
        int L = S[i].size();
        for (int j = 0; j < L; j++) {
            if (S[i][j] != S[i][L - j - 1]) {
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