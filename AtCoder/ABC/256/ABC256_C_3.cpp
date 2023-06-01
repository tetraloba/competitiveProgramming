//2022/08/15 20:11:58
//2022/08/15 20:44:51 AC.
#include <iostream>
using namespace std;
int main(){
    int h[3], w[3], cnt = 0; cin >> h[0] >> h[1] >> h[2] >> w[0] >> w[1] >> w[2];
    for (int i = 1; i <= 28; i++) for (int j = 1; j<= 28; j++) for (int k = 1; k <= 28; k++) for (int l = 1; l <= 28; l++) if (1 <= h[0] - i - j && 1 <= h[1] - k - l && 1 <= w[0] - i - k && 1 <= w[1] - j - l && 1 <= w[2] - h[0] - h[1] + i + j + k + l && w[2] - h[0] -h[1] + i + j + k + l == h[2] - w[0] - w[1] + i + j + k + l) cnt++;
    cout << cnt << endl;
    return 0;
}