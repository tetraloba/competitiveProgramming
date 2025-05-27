// 2024/12/03 13:29:44
// 2024/12/03 15:18:50 TLE
// 2024/12/03 16:03:44 AC.
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Pos{
    public:
        int row;
        int col;
        Pos operator+(Pos);
};
Pos Pos::operator+(Pos other){
    return {this->row + other.row, this->col + other.col};
}

int H, W, K;
Pos dir4[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool is_outside(Pos pos){
    return pos.row < 0 || H <= pos.row || pos.col < 0 || W <= pos.col;
}

int main(){
    cin >> H >> W >> K;
    vector<string> S(H);
    for (string &s : S) {
        cin >> s;
    }
    long long ans = 0;
    for (int r = 0; r < H; r++) {
        for (int c = 0; c < W; c++) {
            if (S[r][c] != '.') {
                continue;
            }
            stack<Pos> route;
            vector<vector<bool>> done(H, vector<bool>(W));
            stack<pair<Pos, int>> stk; // pos, dist
            stk.push({{r, c}, 0});
            while (!stk.empty()) {
                auto [tgt, dist] = stk.top(); stk.pop();
                while (dist < route.size()) {
                    Pos e = route.top(); route.pop();
                    done[e.row][e.col] = false;
                }
                if (dist == K) {
                    ans++;
                    continue; // これ以上進まない
                }
                route.push(tgt);
                done[tgt.row][tgt.col] = true;
                // cerr << r << ',' << c << "->" << tgt.row << ',' << tgt.col << endl; // debug
                for (int d = 0; d < 4; d++) {
                    Pos next = tgt + dir4[d];
                    if (is_outside(next)) {
                        continue;
                    }
                    if (S[next.row][next.col] != '.') {
                        continue;
                    }
                    if (done[next.row][next.col]) {
                        continue;
                    }
                    stk.push({next, dist + 1});
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
/*
お、bitDPか？(にっこり) (2024/12/03 13:30:51)
じゃなくても解けるような気がするが、
せっかくだから、オレはこのbitDPを選ぶぜ！(2024/12/03 13:31:28)
いや100マス有るじゃないか無理じゃないか(2024/12/03 13:34:18)
全探索だとO((HW)P(K))、あるいはO(HW×4^K)=4.2e8
まあ、普通に、通ったマスをsetで持つのでも行けるのかなあ・・・?(2024/12/03 13:49:25)

setのコピーコンストラクタが参照渡しになるのを理解していなくて詰まった。
set使うとTLEか・・・(2024/12/03 15:21:38)
*/
