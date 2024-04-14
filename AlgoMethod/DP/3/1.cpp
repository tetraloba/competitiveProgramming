// 2024/04/14 15:32:19
// 2024/04/14 15:41:46 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> A(N - 1);
    for (int &a : A) {
        cin >> a;
    }
    vector<vector<bool>> vv(N, vector<bool>(M));
    vv[0][0] = true;
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M; j++) {
            if (!vv[i][j]) {
                continue;
            }
            if (i < M - 1 && j + A[i] < M) {
                vv[i + 1][j + A[i]] = true;
            }
            vv[i + 1][j] = true;
        }
    }
    int ans = 0;
    for (bool b : vv[N - 1]) {
        if (b) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
