//2022/08/05 08:19:51
//2022/08/05 08:56:00 TLE
#include <iostream>
using namespace std;
void countFunc(int[][1002], int, int, int*);
int main(){
    int H, W, a[1002][1002] = {0};
    cin >> H >> W;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> a[i][j];
        }
    }
    int cnt = 0;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            int crtR = i, crtC = j;
            cnt++;
            countFunc(a, crtR, crtC, &cnt);
        }
    }
    cout << cnt << '\n';
    return 0;
}
void countFunc(int a[][1002], int crtR, int crtC, int *cnt){
    int dir4[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    for (int i = 0; i < 4; i++) {
        // cout << a[crtR][crtC] << ':' << a[crtR + dir4[i][0]][crtC + dir4[i][1]] << endl;
        if (a[crtR][crtC] < a[crtR + dir4[i][0]][crtC + dir4[i][1]]) {
            (*cnt)++;
            countFunc(a, crtR + dir4[i][0], crtC + dir4[i][1], cnt);
        }
    }
    return;
}
//dir4配列使ってみたよ 2022/08/05 09:53:27