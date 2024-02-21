// 2024/02/21 12:40:40
// 2024/02/21 13:09:09 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> S(M);
    for (auto &s: S) {
        int C;
        cin >> C;
        for (int i = 0; i < C; i++) {
            int tmp;
            cin >> tmp;
            s |= (1 << tmp - 1);
        }
    }

    int ans = 0;
    for (int bi = 1; bi < (1 << M); bi++) {
        int bf = 0;
        for (int i = 0; i < M; i++) {
            if ((bi >> i) % 2) {
                bf |= S[i];
            }
        }
        if (bf == (1 << N) - 1) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
// bit演算、シフト演算、集合演算を使って解ける。
// なお可読性はゴミなので2ヶ月後には読めない自信がある。
