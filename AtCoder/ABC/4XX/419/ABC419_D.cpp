// 2025/12/14 02:22:06
// 2025/12/14 02:29:17 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;
    vector<int> swap_cnts(N + 1); // S[i]のswap回数
    for (int i = 0; i < M; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        swap_cnts[l]++;
        swap_cnts[r + 1]--;
    }
    for (int i = 1; i <= N; i++) {
        swap_cnts[i] += swap_cnts[i - 1];
    }
    for (int i = 0; i < N; i++) {
        cout << (swap_cnts[i] & 1 ? T : S)[i];
    }
    cout << endl;
    return 0;
}
/*
2025/12/14 02:23:31
swapのlとrだけ更新する01配列を作ればよいのか。
*/

