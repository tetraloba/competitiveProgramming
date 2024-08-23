// 2024/08/24 08:05:04
// 2024/08/24 08:39:31 むりかも
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<pair<int, int>> XY(N);
    for (auto &xy : XY) {
        cin >> xy.first >> xy.second;
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int p = XY[i].first - XY[j].first;
            int q = XY[i].second - XY[j].second;
            int cnt = 1;
            for (int k = 0; k < N; k++) {
                for (int l = 0; l < N; l++) {
                    if (k == i || l == j) {
                        continue;
                    }
                    if (XY[k].first - XY[l].first == p && XY[k].second - XY[l].second == q) {
                        cnt++;
                    }
                }
            }
            ans = max(cnt, ans);
        }
    }
    cout << ans << endl;
    return 0;
}
/*
1次元でも同じように考えられるよね。(2024/08/24 08:18:46)
1 3 7 9
で
1 7 3 9みたいな。
ん、これだとコスト同じだが・・(2024/08/24 08:20:03)
1 9 7 3 はもちろん違うし。
1 7 3 9 15

各間50x50を考えて、(p,q)の候補はたかだか2500通りしか無いので、
2500x2500で解ける？(2024/08/24 08:26:23)
*/
/*
あーこれは良い問題だな。解けるようにしないとな。
*/
