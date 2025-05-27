// 2025/01/12 14:34:25
// 2025/01/12 15:00:28 AC.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Pos{
    int h;
    int w;
};
struct Node{
    Pos pos;
    int depth;
    bool next_horizontal;
};

int H, W;
vector<string> S;
Pos dir4[2][2] = {{{1, 0}, {-1, 0}}, {{0, 1},  {0, -1}}};
bool outside(Pos pos){
    return pos.h < 0 || H <= pos.h || pos.w < 0 || W <= pos.w;
}
bool can_move(Pos pos){
    if (outside(pos)) {
        return false;
    }
    if (S[pos.h][pos.w] == '#') {
        return false;
    }
    return true;
}
int main(){
    cin >> H >> W;
    S = vector<string>(H);
    for (string &s : S) {
        cin >> s;
    }

    /* BFS */
    vector<vector<vector<bool>>> done(2, vector<vector<bool>>(H, vector<bool>(W)));
    queue<Node> que;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (S[h][w] != 'S') {
                continue;
            }
            for (int hor = 0; hor <= 1; hor++) {
                for (Pos d : dir4[hor]) {
                    Pos next = {h + d.h, w + d.w};
                    if (!can_move(next)) {
                        continue;
                    }
                    if (done[!hor][next.h][next.w]) {
                        continue;
                    }
                    done[!hor][next.h][next.w] = true;
                    que.push({next, 1, !hor});
                }
            }
        }
    }

    while (!que.empty()) {
        Node tgt = que.front(); que.pop();
        // cerr << tgt.pos.h << ',' << tgt.pos.w << ':' << tgt.next_horizontal << endl;
        if (S[tgt.pos.h][tgt.pos.w] == 'G') {
            cout << tgt.depth << endl;
            return 0;
        }
        for (Pos d : dir4[tgt.next_horizontal]) {
            Pos next = {tgt.pos.h + d.h, tgt.pos.w + d.w};
            if (!can_move(next)) {
                continue;
            }
            if (done[!tgt.next_horizontal][next.h][next.w]) {
                continue;
            }
            done[!tgt.next_horizontal][next.h][next.w] = true;
            que.push({next, tgt.depth + 1, !tgt.next_horizontal});
        }
    }
    cout << "-1" << endl;
    return 0;
}
/*
うーん頑張ってBFS実装すれば間に合いそうだけど？
*/
