// 2025/03/01 22:51:24
// 2025/03/01 23:49:26 give up
// 2025/03/02 10:01:57 restart
// 2025/03/02 10:13:47 AC.
#include <iostream>
#include <vector>
using namespace std;
using pos = pair<int, int>;
bool inside(pos p) {
    return 0 <= p.first && p.first <= 5000 && 0 <= p.second && p.second <= 5000;
}
int main(){
    int n;
    cin >> n;
    vector<vector<bool>> exist(5001, vector<bool>(5001));
    vector<pos> ps(n);
    for (pos &p : ps) {
        cin >> p.first >> p.second;
        exist[p.first][p.second] = true;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // ps[i], ps[j]を対角線とする正方形を考える
            pos middle2 = {ps[i].first + ps[j].first, ps[i].second + ps[j].second}; // 対角線の中点 (正方形の中心) (倍座標)
            int x_diff2 = ps[i].first * 2 - middle2.first;
            int y_diff2 = ps[i].second * 2 - middle2.second;
            pos reqv0 = {(middle2.first - y_diff2) / 2, (middle2.second + x_diff2) / 2}; // 残りの必要な頂点
            pos reqv1 = {(middle2.first + y_diff2) / 2, (middle2.second - x_diff2) / 2};
            // cerr << ps[i].first << '-' << ps[i].second << ' ' << ps[j].first << '-' << ps[j].second << ' ' << reqv0.first << '-' << reqv0.second << ' ' << reqv1.first << '-' << reqv1.second << endl; // debug
            if (inside(reqv0) && inside(reqv1) && exist[reqv0.first][reqv0.second] && exist[reqv1.first][reqv1.second]) {
                ans = max(ans, (x_diff2 * x_diff2 + y_diff2 * y_diff2) / 2);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
/*
n <= 3000なのでO(nC2)くらいなら間に合うのかしらね。(2025/03/01 22:53:43)
30, 02, 25, 53
x1 + x3 + y1 + y3 = x2 + x4 + y2 + y4
x1^2 + x2^2 - 2*x1*x2 + y1^2 + y2^2 - 2 * y1 * y2
対角線の2点が求まっていたら残りの対角線の2点を求められるはずだが公式がわからん(2025/03/01 23:49:52)
*/
