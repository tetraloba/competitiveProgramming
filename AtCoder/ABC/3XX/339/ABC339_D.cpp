// 2025/03/26 13:58:23
// 2025/03/26 15:40:03 43TLE
// 2025/03/26 16:01:32 give up
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
class pos{
    public:
        int r;
        int c;
        pos();
        pos(int, int);
        pos operator+(pos);
        bool operator==(pos);
        // bool operator<(pos);
};
pos::pos() {
    this->r = 0;
    this->c = 0;
}
pos::pos(int r, int c) {
    this->r = r;
    this->c = c;
}
pos pos::operator+(pos other) {
    return {this->r + other.r, this->c + other.c};
}
bool pos::operator==(pos other) {
    return this->r == other.r && this->c == other.c;
}
// bool pos::operator<(pos other) {
//     return (this->r == other.r && this->c < other.c) || this->r < other.r;
// }
bool operator<(const pos &l, const pos &r) {
    return (l.r == r.r && l.c < r.c) || l.r < r.r;
}

class board{
    public:
        pos p0; // player0の座標
        pos p1; // player1の座標
        int opr; // 操作回数
        board(pos, pos, int);
};
board::board(pos p0, pos p1, int opr) {
    this->p0 = p0;
    this->p1 = p1;
    this->opr = opr;
}

const pos dir4[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int N;
vector<string> S;
vector<vector<set<pos>>> vv;

bool can_move(pos p) {
    if (p.r < 0 || N <= p.r || p.c < 0 || N <= p.c) {
        return false;
    }
    return S[p.r][p.c] != '#';
}

int main() {
    cin >> N;
    S = *(new vector<string>(N));
    for (string &s : S) {
        cin >> s;
    }

    vv = *(new vector<vector<set<pos>>>(N, vector<set<pos>>(N)));
    
    vector<pos> players;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (S[i][j] == 'P') {
                players.push_back({i, j});
            }
        }
    }

    queue<board> que;
    que.push({players[0], players[1], 0});
    // cerr << players[0].r << ' ' << players[0].c << " to " << players[1].r << ' ' << players[1].c << endl; // debug
    while (!que.empty()) {
        board tgt = que.front(); que.pop();
        // cerr << tgt.p0.r << ' ' << tgt.p0.c << ' ' << tgt.p1.r << ' ' << tgt.p1.c << ' ' << tgt.opr << endl; // debug
        vv[tgt.p0.r][tgt.p0.c].insert(set<pos>::value_type(tgt.p1));
        if (tgt.p0 == tgt.p1) {
            cout << tgt.opr << endl;
            return 0;
        }
        for (pos d : dir4) {
            pos next0 = tgt.p0 + d;
            pos next1 = tgt.p1 + d;
            if (!can_move(next0)) {
                next0 = tgt.p0;
            }
            if (!can_move(next1)) {
                next1 = tgt.p1;
            }
            if (vv[next0.r][next0.c].count(set<pos>::value_type(next1))) {
                continue; // 既に処理済み
            }
            que.push({next0, next1, tgt.opr + 1});
        }
        /* debug */
        // for (int i = 0; i < N; i++) {
        //     for (int j = 0; j < N; j++) {
        //         cerr << vv[i][j] << ' ';
        //     }
        //     cerr << endl;
        // }
    }

    cout << -1 << endl;
    return 0;
}
/*
片方だけ動ける場合にのみ距離が縮まるわけか…
最初の差分をどうやって解消するかを考える方針ってことよね。(2025/03/26 14:00:30)
合流できない条件は？外周は壁扱いだから，プレイヤの座標間を移動する経路さえ有れば必ず合流できる？(2025/03/26 14:02:53)
########
###.####
##432###
#.P#1P##
#.###.##
#..#..##
##...###
########
行けるのかなあ…(2025/03/26 14:07:23)
一方が他方に近づくように動き続ける，というアルゴリズムでも正解できそうだが，計算量が如何ほどか。(2025/03/26 14:08:15)
最小手数であることが証明できないといけないのか。(2025/03/26 14:08:49)
とりあえず実装してみるか。テストケース弱いからWAやTLE出たら終わりだけど。(2025/03/26 14:09:46)

最適解にならないなあ(2025/03/26 15:08:22)
うーん，全探索するかあ？(2025/03/26 15:13:20)
6
......
.####.
.#P.#.
.#..#.
.####.
.P....

流石にTLEね。
ワーシャルフロイドとか使ったりするのかしら？(2025/03/26 15:59:59)

*/

