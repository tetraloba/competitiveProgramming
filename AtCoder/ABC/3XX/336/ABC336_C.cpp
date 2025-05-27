// 2024/02/23 22:33:40
// 2024/02/23 22:53:45 WA
// 2024/02/23 22:55:44 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    long long N; // 残りの個数
    cin >> N;
    if (N == 1) {
        cout << 0 << endl;
        return 0;
    }
    N--; // N番目はN-1の5進数表記の2倍
    vector<int> ans_r(0); // 答えの数列の逆順
    while (N) {
        int v = N % 5; // 0 ~ 4
        ans_r.push_back(v * 2); // 0,2,4,6,8 に直して格納
        N /= 5;
    }
    // ans_r を逆順で出力
    for (int i = ans_r.size() - 1; 0 <= i; i--) {
        cout << ans_r[i];
    }
    cout << endl;
    return 0;
}
