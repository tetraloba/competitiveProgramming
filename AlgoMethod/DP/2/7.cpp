// 2024/04/13 17:32:50
// 2024/04/13 17:37:45 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    for (auto &v : A) {
        for (int &a : v) {
            cin >> a;
        }
    }

    vector<vector<int>> vv(N, vector<int>(N, __INT32_MAX__));
    vv[0][N - 1] = A[0][N - 1];
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; 0 <= j; j--) {
            if (0 < i) {
                vv[i][j] = min(vv[i][j], vv[i - 1][j] + A[i][j]);
            }
            if (j < N - 1) {
                vv[i][j] = min(vv[i][j], vv[i][j + 1] + A[i][j]);
            }
        }
    }
    cout << vv[N - 1][0] << endl;
    return 0;
}
