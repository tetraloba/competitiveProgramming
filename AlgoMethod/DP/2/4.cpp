// 2024/04/13 17:21:09
// 2024/04/13 17:24:18 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<vector<int>> vv(N, vector<int>(N));
    vv[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (0 < i) {
                vv[i][j] += vv[i - 1][j];
            }
            if (0 < j) {
                vv[i][j] += vv[i][j - 1];
            }
        }
    }
    cout << vv[N - 1][N - 1] << endl;
    return 0;
}
