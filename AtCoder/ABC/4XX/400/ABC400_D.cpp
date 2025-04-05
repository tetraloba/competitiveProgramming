// 2025/04/05 21:32:35
// 
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const pair<int, int> dir4[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int solve1(int H, int W, vector<string> &S, int A, int B, int C, int D){
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pque;
    vector<vector<int>> min_dists(H, vector<int>(W, INT32_MAX));
    pque.push({0, {A, B}});
    min_dists[A][B] = 0;
    while (!pque.empty()) {
        auto [dist, tgt] = pque.top(); pque.pop();
        if (tgt.first == C && tgt.second == D) {
            return dist;
        }
        for (pair<int, int> d : dir4) {
            pair<int, int> next = {tgt.first + d.first, tgt.second + d.second};
            if (next.first < 0 || H <= next.first || next.second < 0 || W <= next.second) {
                continue; // out of range
            }
            int next_dist = dist + (S[next.first][next.second] == '#' ? 1 : 0);
            if (min_dists[next.first][next.second] <= next_dist) {
                continue;
            }
            pque.push({next_dist, next});
            min_dists[next.first][next.second] = next_dist;
        }
    }
    return -1;
}
int solve2(int H, int W, vector<string> &S, int A, int B, int C, int D) {
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            ;
        }
    }
}
int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (string &s : S) {
        cin >> s;
    }
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    A--; B--; C--; D--;
    solve2()
}
/*
壁を通り抜けられるが通り抜けた数を累積していくような，かつ通り抜けた数が少ないものから優先して処理していくような幅優先探索？(2025/04/05 21:37:28)
壁を2つ破壊できるというのが厄介だな。(2025/04/05 21:52:12)
先に破壊無しで移動できる領域を塗り分けておいて，領域間の重み付きグラフを考えないといけない？(2025/04/05 21:52:44)
#.#.#
.#.#.
領域数は高々HW/2 = 500,000
完全グラフを考えるのは無理だよな。"隣接"した領域という概念は有るか？(2025/04/05 21:56:34)
いや，当初の解法で前の場所も壁だったかを判定するほうが容易か。(2025/04/05 21:58:27)
向きの情報も必要だよな。
.###
##.#
の場合は2回蹴らないといけない(2025/04/05 21:59:25)
いや1回で行けるのか。これどういう条件だ・・・(2025/04/05 21:59:46)
.###
####
##.
分からん，とりあえず実装する・・・？(2025/04/05 22:00:32)
*/
/*
解説を読んで
あーなるほどおおお
グラフってそう実装するのかああ・・・
いやあ，案1と案2をうまく組み合わせたような考え方をしないといけなかったなあ。
勉強になった。(2025/04/05 22:44:22)
優先度付きキューとかも良い発想だったが，01-BFSなるものが有るのか。勉強しよう。(2025/04/05 22:44:54)
*/

