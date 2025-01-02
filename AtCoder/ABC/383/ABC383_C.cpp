// 2025/01/02 09:48:28
// 2025/01/02 10:10:02 TLE
// 2025/01/02 10:24:49 AC.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Pos{
    int h;
    int w;
};
Pos DIR4[4] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
struct Node{
    Pos pos;
    int humidity;
};

int H, W, D;
bool outside(Pos pos) {
    return pos.h < 0 || H <= pos.h || pos.w < 0 || W <= pos.w;
}
int main(){
    cin >> H >> W >> D;
    vector<string> S(H);
    for (string &s : S) {
        cin >> s;
    }
    
    vector<vector<int>> humidity(H, vector<int>(W));
    queue<Node> que;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (S[h][w] == 'H') {
                que.push({h, w, D + 1});
            }
        }
    }
    while (!que.empty()) {
        Node tgt = que.front(); que.pop();
        if (tgt.humidity <= humidity[tgt.pos.h][tgt.pos.w]) {
            continue;
        }
        humidity[tgt.pos.h][tgt.pos.w] = tgt.humidity;
        for (Pos dir : DIR4) {
            Node next = {tgt.pos.h + dir.h, tgt.pos.w + dir.w, tgt.humidity - 1};
            if (outside(next.pos)) {
                continue;
            }
            if (S[next.pos.h][next.pos.w] != '.') {
                continue;
            }
            if (next.humidity <= humidity[next.pos.h][next.pos.w]) {
                continue;
            }
            que.push(next);
        }
    }

    // /* debug */
    // for (int h = 0; h < H; h++) {
    //     for (int w = 0; w < W; w++) {
    //         cerr << humidity[h][w] << ' ';
    //     }
    //     cerr << endl;
    // }

    /* ans (count) */
    int ans = 0;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (0 < humidity[h][w]) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
/*
単純な問題だけど、これどうするんだ？
Dから塗り拡げていけば良い？ 2025/01/02 09:51:57
んーDFSだとTLEか・・・？
最初に'H'を全部PUSHして幅優先のほうが良いのか？計算量見積もれないンゴ…(2025/01/02 10:20:31)
確かに、BFSなら塗り直しが起こり得ないのか。
*/
