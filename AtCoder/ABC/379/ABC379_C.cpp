// 2024/12/06 07:44:48
// 2024/12/06 08:14:21 WA
// 2024/12/06 08:29:22 WA
// 2024/12/06 08:32:51 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> X(M), A(M);
    for (int &x : X) {
        cin >> x;
    }
    for (int &a: A) {
        cin >> a;
    }

    vector<pair<int, long long>> stones; // マス, 石の数
    for (int i = 0; i < M; i++) {
        stones.push_back({X[i], A[i]});
    }
    stones.push_back({N + 1, 0}); // 便宜上
    sort(stones.begin(), stones.end());

    if (stones[0].first != 1) {
        cout << "-1" << endl;
        return 0;
    }
    long long ans = 0;
    for (int i = 0; i < M; i++) {
        int dist = stones[i + 1].first - stones[i].first;
        if (stones[i].second < dist) {
            cout << "-1" << endl;
            return 0;
        }
        ans += (long long)(1 + (dist - 1)) * (dist - 1) / 2; // 間のマスに石を入れる
        ans += (stones[i].second - dist) * dist; // 余った石を次の石のマスに移動
        stones[i + 1].second += stones[i].second - dist;
        // cerr << i << ':' << ans << endl; // debug
    }
    if (stones[M].second != 0) { // 石が余る
        cout << "-1" << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}
/*
石のある場所と数をスタックに詰めつつ左からO(N)かな。(2024/12/06 07:46:04)
O(N)は間に合わないのね。じゃあO(M)で計算だな。(2024/12/06 07:47:31)
全マスにちょうど1個になるなら、マスが貰うんじゃなくてマスに配るように考えたほうが良いか。(2024/12/06 08:01:40)
全マスに少なくとも1個の方が多少難しい？(2024/12/06 08:02:44)
*/
/*
最後に石が余る(マスが足りない)場合の処理に手こずった…(2024/12/06 08:33:23)
*/
