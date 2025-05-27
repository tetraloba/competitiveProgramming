// 2024/12/03 13:29:44
// 2024/12/03 15:18:50 TLE
#include <iostream>
#include <vector>
#include <stack>
#include <set>
using namespace std;
int H, W, K;
pair<int, int> dir4[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int r_of(int pos){
    return pos / W;
}
int c_of(int pos){
    return pos % W;
}
int to_pos(int row, int col){
    return row * W + col;
}
// void debug(set<int> st){
//     for (int pos : st) {
//         cerr << '(' << r_of(pos) << ',' << c_of(pos) << ')' << ' ';
//     }
//     cerr << endl;
// }
bool is_outside(int r, int c){
    return r < 0 || H <= r || c < 0 || W <= c;
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
            // cerr << "start from: " << r << ',' << c << endl;
            int pos = to_pos(r, c);
            stack<pair<int, set<int>>> stk;
            set<int> route;
            route.insert(pos);
            stk.push({pos, route});
            while (!stk.empty()) {
                auto [tgt, st] = stk.top(); stk.pop();
                // cerr << "\ttgt: " << r_of(tgt) << ',' << c_of(tgt) << ':';
                // debug(st);
                for (int d = 0; d < 4; d++) {
                    int next_r = r_of(tgt) + dir4[d].first;
                    int next_c = c_of(tgt) + dir4[d].second;
                    if (is_outside(next_r, next_c)) {
                        continue;
                    }
                    if (S[next_r][next_c] != '.') {
                        continue;
                    }
                    int next = to_pos(next_r, next_c);
                    if (st.count(next)) {
                        continue;
                    }
                    set<int> new_st(st);
                    new_st.insert(next);
                    if (new_st.size() == K + 1) {
                        // cerr << "found! ";
                        // debug(new_st);
                        ans++;
                        continue;
                    }
                    // cerr << "\t\tnext: " << next_r << ',' << next_c << endl;
                    stk.push({next, new_st});
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
