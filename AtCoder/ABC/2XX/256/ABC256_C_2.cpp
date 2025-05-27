//2022/08/15 20:11:58
//丁寧に埋めるならこう
//2022/08/15 20:33:25 AC.
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int h[3], w[3], a[3][3];
    cin >> h[0] >> h[1] >> h[2] >> w[0] >>  w[1] >> w[2];
    sort(h, &h[2]), sort(w, &w[2]);
    int cnt = 0;
    for (int i = 1; i <= 28; i++) {
        a[0][0] = i;
        for (int j = 1; j<= 28; j++) {
            a[0][1] = j;
            a[0][2] = h[0] - a[0][0] - a[0][1];
            if (a[0][2] < 1) {
                continue;
            }
            for (int k = 1; k <= 28; k++) {
                a[1][0] = k;
                a[2][0] = w[0] - a[0][0] - a[1][0];
                if (a[2][0] < 1) {
                    continue;
                }
                for (int l = 1; l <= 28; l++) {
                    a[1][1] = l;
                    a[1][2] = h[1] - a[1][0] - a[1][1];
                    a[2][1] = w[1] - a[0][1] - a[1][1];
                    if (a[1][2] < 1 || a[2][1] < 1) {
                        continue;
                    }
                    a[2][2] = h[2] - a[2][0] - a[2][1];
                    if (1 <= a[2][2] && a[2][2] == w[2] - a[0][2] - a[1][2]) {
                        cnt++;
                    }
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}