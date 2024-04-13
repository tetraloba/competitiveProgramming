// 2024/04/13 09:30:24
// 2024/04/13 09:34:51 AC.
#include <iostream>
#include <vector>
using namespace std;
pair<int, int> DIR3[3] = {{-1, -1}, {-1, 0}, {-1, 1}};
int main(){
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    for (int &a : A[0]) {
        cin >> a;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int d = 0; d < 3; d++) {
                pair<int, int> src = {i + DIR3[d].first, j + DIR3[d].second};
                if (0 <= src.first && src.first < N && 0 <= src.second && src.second < N) {
                    A[i][j] += A[src.first][src.second];
                    A[i][j] %= 100;
                }
            }
        }
    }
    cout << A[N - 1][N - 1] << endl;
    return 0;
}
