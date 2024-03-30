// 2024/03/30 16:25:12
// 2024/03/30 17:16:48 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    pair<int, int> V[4];
    for (int i = 0; i < 4; i++) {
        cin >> V[i].first >> V[i].second;
    }
    int cnt_posi = 0;
    for (int i = 0; i < 4; i++) {
        int a = i;
        int b = (a + 1) % 4;
        int c = (b + 1) % 4;
        double Vcsecond = V[a].second + (V[b].second - V[a].second) * (V[c].first - V[a].first) / (double)(V[b].first - V[a].first);
        // cout << Vcsecond << ' '; // debug
        if (V[a].first < V[b].first) {
            cnt_posi += V[c].second > Vcsecond;
            // if (V[a].second < V[b].second) {
            //     /* 第四象限のイメージ */
            //     cnt_posi += V[c].second > Vcsecond;
            //     cout << (V[c].second > Vcsecond) << ' ';
            // } else {
            //     /* 第三象限のイメージ */
            //     cnt_posi += V[c].second > Vcsecond;
            //     cout << (V[c].second > Vcsecond) << ' ';
            // }
        } else if (V[a].first > V[b].first) {
            cnt_posi += V[c].second < Vcsecond;
            // if (V[a].second < V[b].second) {
            //     /* 第一象限のイメージ */
            //     cnt_posi += V[c].second < Vcsecond;
            //     cout << (V[c].second < Vcsecond) << ' ';
            // } else{
            //     /* 第二象限のイメージ */
            //     cnt_posi += V[c].second < Vcsecond;
            //     cout << (V[c].second < Vcsecond) << ' ';
            // }
        } else {
            /* V[a].first == V[b].first */
            if (V[a].second < V[b].second) {
                cnt_posi += V[c].first < V[a].first;
            } else {
                cnt_posi += V[c].first > V[a].first;
            }
        }
    }
    cout << (cnt_posi == 4 ? "Yes" : "No") << endl;
    return 0;
}
/*
角ABCが180度以上であるかどうかを判定するには、直線ABに対してCが内側と外側のどちらに居るかを評価すれば良い。
内側と外側はAとBの位置関係によって変わる。(2024/03/30 16:31:16)
か、三角関数の計算をすれば求まる。(2024/03/30 16:32:06)
*/
