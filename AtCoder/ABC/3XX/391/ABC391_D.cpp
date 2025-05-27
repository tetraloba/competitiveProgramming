// 2025/02/27 10:27:43
// 2025/02/27 12:57:19 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Block{
    public:
        int x;
        int y;
        int n;
        int del_time;
        bool operator<(Block &other);
};
bool Block::operator<(Block &other){
    if (this->x < other.x) {
        return true;
    }
    if (other.x < this->x) {
        return false;
    }
    if (this->y < other.y) {
        return true;
    }
    return false;
}
bool comp_block_ptr(Block *ptr1, Block *ptr2){
    return *ptr1 < *ptr2;
}
int main(){
    int N, W;
    cin >> N >> W;
    vector<vector<Block*>> x_block_ptrs(W); // x列目のブロックのポインタのリスト
    vector<Block> blocks(N); // i番目のブロックへのポインタ
    for (int i = 0; i < N; i++) {
        int X, Y;
        cin >> X >> Y;
        X--; Y--;
        blocks[i] = *(new Block({X, Y, i, INT32_MAX}));
        x_block_ptrs[X].push_back(&blocks[i]);
    }
    for (int w = 0; w < W; w++) {
        sort(x_block_ptrs[w].begin(), x_block_ptrs[w].end(), comp_block_ptr);
    }

    int min_row = INT32_MAX; // 各列のブロック数の内，最も少ないブロック数 (最終的に消える段数)
    for (int w = 0; w < W; w++) {
        min_row = min(min_row, (int)x_block_ptrs[w].size());
    }

    vector<int> del_times(min_row); // i段目が消える時刻
    for (int r = 0; r < min_row; r++) {
        /* 各列のi段目の(=i番目に消える)ブロックの内，着地が最も遅いものに律速される */
        for (int w = 0; w < W; w++) {
            del_times[r] = max(del_times[r], x_block_ptrs[w][r]->y);
        }
    }
    for (int r = 1; r < min_row; r++) {
        /* 下の段が消えるまでは消えない */
        del_times[r] = max(del_times[r], del_times[r - 1] + 1);
    }

    /* 各ブロックのdel_timeを設定 */
    for (int r = 0; r < min_row; r++) {
        for (int w = 0; w < W; w++) {
            x_block_ptrs[w][r]->del_time = del_times[r];
        }
    }

    /* debug */
    // for (Block block : blocks) {
    //     cerr << block.del_time << ' ';
    // }
    // cerr << endl;

    /* クエリに回答 */
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        int t, a;
        cin >> t >> a;
        a--;
        cout << (t <= blocks[a].del_time ? "Yes" : "No") << endl;
    }
    return 0;
}
/*
最初に，1行目に1つでも空きブロックが有るならば，1秒で全部着地させる？(2025/02/27 11:22:47)
列内での入れ替わりはないので，どのブロックが"何番目に消えるか"は決まっているのね。
消えるとか考えずに，y軸マイナス座標まで動かしていって，全ての列でその番目に消えるブロックがy=0になったときにその段が消えたとみなす，みたいな実装でも良いのかしら。(2025/02/27 11:46:24)
*/
/*
クラスとか使って余計なことはしているが，基本的には想定解って感じだね。
2時間30分だけど，実際には間でSMZ先輩の卒論発表練習に参加したり洗濯物干したり昼食食べたりしている。
*/
