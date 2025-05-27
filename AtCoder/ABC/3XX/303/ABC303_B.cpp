// 2023/10/30 10:54:33
// 2023/10/30 11:12:12 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> a(M, vector<int>(N));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<bool>> discord(N, vector<bool>(N, true));
    for (int i = 0; i < N; i++) {
        discord[i][i] = false;
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N - 1; j++) {
            discord[a[i][j] - 1][a[i][j + 1] - 1] = false;
            discord[a[i][j + 1] - 1][a[i][j] - 1] = false;
        }
    }
    /* debug */
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << discord[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    unsigned int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (discord[i][j]) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}
