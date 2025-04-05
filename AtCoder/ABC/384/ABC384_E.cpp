// 2025/04/05 11:10:21
// 2025/04/05 11:52:22 AC.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
pair<int, int> dir4[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool outside(int H, int W, pair<int, int> p) {
    return p.first < 0 || H <= p.first || p.second < 0 || W <= p.second;
}
int main() {
    int H, W, X, P, Q;
    cin >> H >> W >> X >> P >> Q;
    P--; Q--;
    vector<vector<long long>> S(H, vector<long long>(W));
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            cin >> S[h][w];
        }
    }

    long long T = S[P][Q]; // 高橋強さ
    priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<pair<long long, pair<int, int>>>> pque;
    S[P][Q] = 0;
    pque.push({S[P][Q], {P, Q}});
    while (!pque.empty()) {
        auto tgt = pque.top(); pque.pop();
        // cerr << tgt.first << ' ' << tgt.second.first << ' ' << tgt.second.second << endl; // debug
        if (T % X ? T / X < tgt.first : T / X <= tgt.first) {
            break;
        }
        T += tgt.first;
        for (pair<int, int> d : dir4) {
            pair<int, int> next_pos = {tgt.second.first + d.first, tgt.second.second + d.second};
            if (outside(H, W, next_pos)) {
                continue;
            }
            if (S[next_pos.first][next_pos.second] == 0) {
                continue;
            }
            pque.push({S[next_pos.first][next_pos.second], next_pos});
            S[next_pos.first][next_pos.second] = 0;
        }
    }
    cout << T << endl;
    return 0;
}
/*
吸収する順番は関係ない。吸収しきった後の盤面は1通り。
隣接するスライムの強さを昇順で取り出す優先度付きキューが有れば良い。(2025/04/05 11:15:35)
*/
/*
解説で強さの比較方法について検討している。浮動小数点数を使う方法(誤算の問題)，移行して掛け算にする方法(オーバーフローの問題)等。
> https://atcoder.jp/contests/abc384/editorial/11691
*/
