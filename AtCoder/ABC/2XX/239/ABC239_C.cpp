// 2024/03/05 20:09:02
// 2024/03/05 20:23:27 AC.
#include <iostream>
#include <vector>
#include <math.h>
#include <set>
#include <algorithm>
using namespace std;
int main(){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    pair<int, int> p8[8] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
    set<pair<int, int>> st1, st2, co_st;
    for (int i = 0; i < 8; i++) {
        st1.insert({x1 + p8[i].first, y1 + p8[i].second});
        st2.insert({x2 + p8[i].first, y2 + p8[i].second});
    }
    set_intersection(st1.begin(), st1.end(), st2.begin(), st2.end(), inserter(co_st, co_st.end()));
    cout << (co_st.size() ? "Yes" : "No") << endl;
    return 0;
}
/*
まあ色々とやり方は有りそう。
僕は問題文に忠実に、各点からの距離が√5である格子点の集合を作って、それらの積集合を求めることで共通の格子点が有るかを調べた。
*/
