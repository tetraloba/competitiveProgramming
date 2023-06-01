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
    // cout << a[crtR][crtC] << ':' << a[crtR][crtC - 1] << endl;
    if (a[crtR][crtC] < a[crtR][crtC - 1]) {
        (*cnt)++;
        countFunc(a, crtR, crtC - 1, cnt);
    }
    // cout << a[crtR][crtC] << ':' << a[crtR][crtC + 1] << endl;
    if (a[crtR][crtC] < a[crtR][crtC + 1]) {
        (*cnt)++;
        countFunc(a, crtR, crtC + 1, cnt);
    }
    // cout << a[crtR][crtC] << ':' << a[crtR - 1][crtC] << endl;
    if (a[crtR][crtC] < a[crtR - 1][crtC]) {
        (*cnt)++;
        countFunc(a, crtR - 1, crtC, cnt);
    }
    // cout << a[crtR][crtC] << ':' << a[crtR + 1][crtC] << endl;
    if (a[crtR][crtC] < a[crtR + 1][crtC]) {
        (*cnt)++;
        countFunc(a, crtR + 1, crtC, cnt);
    }
    return;
}
//再帰やなあ… 2022/08/05 08:18:22
// 1
// 1 2
// 1 2 4
// 1 2 4 9 -> 4
// 1 4
// 1 4 5
// 1 4 5 9
// 4
// 4 5
// 4 5 9 -> 3
// 5
// 5 9
// 2
// 2 4
// 2 4 9
// 4
// 4 9
// 9