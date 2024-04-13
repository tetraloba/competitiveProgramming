// 2024/04/13 17:27:31
// 2024/04/13 17:32:25 AC.
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
    vector<vector<long long>> vv(N, vector<long long>(N));
    vv[0][0] = A[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (0 < i) {
                vv[i][j] = max(vv[i][j], vv[i - 1][j] + A[i][j]);
            }
            if (0 < j) {
                vv[i][j] = max(vv[i][j], vv[i][j - 1] + A[i][j]);
            }
        }
    }
    cout << vv[N - 1][N - 1] << endl;
    return 0;
}
