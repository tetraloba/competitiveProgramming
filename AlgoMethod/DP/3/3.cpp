// 2024/04/14 16:11:31
// 2024/04/14 16:23:53 RE
// 2024/04/14 16:26:02 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> A(N - 1), B(N - 1);
    for (int &a : A) cin >> a;
    for (int &b : B) cin >> b;
    vector<vector<int>> vv(N, vector<int>(M, -1));
    vv[0][0] = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M; j++) {
            if (vv[i][j] == -1) {
                continue;
            }
            vv[i + 1][j] = max(vv[i + 1][j], vv[i][j]);
            if (j + A[i] < M) {
                vv[i + 1][j + A[i]] = max(vv[i + 1][j + A[i]], vv[i][j] + B[i]);
            }
        }
    }
    cout << vv[N - 1][M - 1] << endl;
    return 0;
}
