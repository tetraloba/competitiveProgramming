// 2024/07/13 12:21:36
// 2024/07/13 12:43:57 AC.
#include <iostream>
#include <vector>
using namespace std;
int N;
int out(pair<int, int> c){
    return c.first < 0 || N <= c.first || c.second < 0 || N <= c.second;
}
int main(){
    const pair<int, int> dir4[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    cin >> N;
    pair<int, int> cur(0, 0);
    vector<vector<int>> grid(N, vector<int>(N, -1));
    int d = 0;
    grid[cur.first][cur.second] = 0;
    for (int i = 1; i < N * N - 1; i++) {
        pair<int, int> cond(cur.first + dir4[d].first, cur.second + dir4[d].second);
        if (out(cond) || grid[cond.first][cond.second] != -1) {
            d = (d + 1) % 4;
        }
        cur = {cur.first + dir4[d].first, cur.second + dir4[d].second};
        grid[cur.first][cur.second] = i;
    }

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (grid[r][c] == -1) {
                cout << "T ";
            } else {
                cout << grid[r][c] + 1 << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}
