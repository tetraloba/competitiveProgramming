// 2025/02/24 11:31:05
// 2025/02/24 11:36:03 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }
    long long ans = 0;
    for (int i = 0; i < M; i++) {
        for (int j = i + 1; j < M; j++) {
            long long score = 0;
            for (int k = 0; k < N; k++) {
                score += max(A[k][i], A[k][j]);
            }
            ans = max(ans, score);
        }
    }
    cout << ans << endl;
    return 0;
}
