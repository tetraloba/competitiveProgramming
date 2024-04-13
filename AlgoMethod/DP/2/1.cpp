// 2024/04/13 09:23:07
// 2024/04/13 09:30:12 AC.
#include <iostream>
#include <vector>
using namespace std;
pair<int, int> DIR[3] = {{-1, -1}, {-1, 0}, {-1, 1}};
int main(){
    int A[4][4] = {0};
    cin >> A[0][0] >> A[0][1] >> A[0][2] >> A[0][3];
    for (int i = 1; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int d = 0; d < 3; d++) {
                pair<int, int> src = {i + DIR[d].first, j + DIR[d].second};
                if (0 <= src.first && src.first < 4 && 0 <= src.second && src.second < 4) {
                    A[i][j] += A[src.first][src.second];
                }
            }
        }
    }
    cout << A[3][3] << endl;
    return 0;
}
