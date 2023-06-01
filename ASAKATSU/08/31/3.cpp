//2022/08/31 07:35:18
//2022/08/31 07:39:10 AC.
//ARC015_B - 真冬日？真夏日？
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    int cnt[6] = {0};
    for (int i = 0; i < N; i++) {
        double M, m;
        cin >> M >> m;
        if (35 <= M) {
            cnt[0]++;
        } else if (30 <= M) {
            cnt[1]++;
        } else if (25 <= M) {
            cnt[2]++;
        }
        if (25 <= m) {
            cnt[3]++;
        }
        if (m < 0 && 0 <= M) {
            cnt[4]++;
        } else if (M < 0) {
            cnt[5]++;
        }
    }
    cout << cnt[0] << ' ' << cnt[1] << ' ' << cnt[2] << ' ' << cnt[3] << ' ' << cnt[4] << ' ' << cnt[5] << endl;
    return 0;
}