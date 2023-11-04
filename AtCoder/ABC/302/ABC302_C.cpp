// 2023/11/04 14:31:50
// 2023/11/04 14:48:51 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    sort(S.begin(), S.end());
    while (true) {
        bool flag = true;
        for (int  i = 0; i < N - 1; i++) {
            unsigned int cnt = 0;
            for (int j = 0; j < M; j++) {
                if (S[i][j] != S[i + 1][j]) {
                    cnt++;
                }
            }
            if (1 < cnt) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "Yes" << endl;
            return 0;
        }
        if (!next_permutation(S.begin(), S.end())) {
            break;
        }
    }
    cout << "No" << endl;
    return 0;
}
// 並べ替え全探索(順列全探索)の問題。
// next_permutation()を使いましょう。
// 再帰で書く方法もあるらしいが…
