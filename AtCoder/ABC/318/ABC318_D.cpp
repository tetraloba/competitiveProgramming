// 2024/05/01 22:10:32
// 
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<vector<int>> D(N + 1, vector<int>(N + 1)); // D[i][j] はiとjを繋いだ時のスコア。j=0は繋がないことを意味し、スコアは0
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N - i; j++) {
            int d;
            cin >> d;
            D[i][i + j] = d;
            D[i + j][i] = d;
        }
    }
    // /* debug */
    // for (auto v : D) {
    //     for (int i : v) {
    //         cout << i << ' ';
    //     }
    //     cout << endl;
    // }
    vector<int> P(N + 1); // 実際に繋ぐ相手
    P[1] = 2; P[2] = 1; // とりあえず頂点1と2を繋ぐ。
    int lone = 0; // 孤立した頂点
    for (int i = 3; i <= N; i++) { // 3個目以降の頂点について
        int max_j = 0, max_v = 0; // 初期値はiが誰とも繋がないこと
        for (int j = 1; j < i; j++) {
            /* i と j が結んだ時 */
            int cp = P[j]; // jの現在のペア
            if (max_v < D[i][j] - D[cp][j] + D[cp][lone]) { // jをiに繋ぎ変えた方が得か？
                max_j = j;
                max_v = D[i][j] - D[cp][j] + D[cp][lone];
            }
        }
        if (max_j) {
            if (lone) { // 孤立頂点が有る
                /* jの元のペアは孤立頂点と接続 */
                P[P[max_j]] = lone;
                P[lone] = P[max_j];
                lone = 0;
            } else {
                P[P[max_j]] = 0; // jの元のペアは切断
                lone = P[max_j];
            }
            /* iはmax_jと接続する */
            P[i] = max_j;
            P[max_j] = i;
        }
    }
    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        // cout << i << ' ' << P[i] << endl; // debug
        ans += D[i][P[i]];
    }
    ans /= 2;
    cout << ans << endl;
    return 0;
}
/*
重みに負はないから、N/2個の辺を選択することは確定しているよね。
各頂点について、ペアを決めていくということでは有る。
2頂点の時選び方は1通りである。
そこから3頂点に増えた時、頂点3と頂点1を結んだときと頂点3と頂点2を結んだときでどちらが良いかで判断する。
頂点4が増えた時は頂点1~3に対して行う。
これでO(16^3)ってことか？(2024/05/01 22:24:26)
それにしては制約がゆるすぎる気がするけど。

1 5 4
7 8
6

1 2 1
1 3 5
1 4 4
2 3 7
2 4 8
3 4 6

これだとO(16^2)だし貪欲法か。
普通にWAになりそうだな。。。(2024/05/01 23:18:06)
少なくとも、繋ぎ変えても変えなくても総和が変わらない場合どちらにすれば良いか分からないから駄目だな。
先を見ないと判断できない。
やはり動的計画法にする必要があるだろう。(2024/05/01 23:31:03)
*/
