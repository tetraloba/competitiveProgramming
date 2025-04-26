// 2025/04/26 21:56:20
// 2025/04/26 22:18:17 15WA
// 2025/04/26 22:23:21 AC.
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    vector<map<int, int>> m(2);
    m[0][1e5 + 1] = 0;
    m[1][1e5 + 1] = 0;
    for(int i = 0; i < n; i++){
        m[i%2][v[i]]++;
    }

    vector<vector<pair<int, int>>> i_cnt(2);
    for (int i = 0; i < 2; i++) {
        for (auto itr = m[i].begin(); itr != m[i].end(); itr++) {
            i_cnt[i].push_back(make_pair(itr->second, itr->first));
        }
    }
    sort(i_cnt[0].rbegin(), i_cnt[0].rend());
    sort(i_cnt[1].rbegin(), i_cnt[1].rend());

    int ans = n;
    for (auto itr1 = i_cnt[0].begin(); distance(i_cnt[0].begin(), itr1) < 2; itr1++) {
        for (auto itr2 = i_cnt[1].begin(); distance(i_cnt[1].begin(), itr2) < 2; itr2++) {
            if (itr1->second == itr2->second) {
                continue;
            }
            ans = min(ans, n - itr1->first - itr2->first);
        }
    }
    cout << ans << endl;
    return 0;
}
/*
偶数番目と奇数番目それぞれにおいて、一番数の多い数を求める
ただし、偶奇でおなじになってはいけない。(2025/04/26 21:59:27)
1番目と2番目を出して、比べればよいか。
*/
