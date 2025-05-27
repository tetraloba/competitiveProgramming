// 2025/03/29 22:23:05
// 2025/03/29 23:07:43 1WA 78RE
// 2025/03/29 23:30:20 65WA
// 2025/03/29 23:31:29 give up ちょっと場合分けがわからないなあ。
#include <iostream>
#include <vector>
#include <set>
#define NUM 26
using namespace std;
int main(){
    int N;
    cin >> N;
    string S, T;
    cin >> S >> T;
    vector<int> trans(NUM, -1);
    for (int i = 0; i < N; i++) {
        if (trans[S[i] - 'a'] != -1 && trans[S[i] - 'a'] != T[i] - 'a') {
            cout << -1 << endl;
            return 0;
        }
        trans[S[i] - 'a'] = T[i] - 'a';
    }

    int free_cnt = 0; // 出現しない文字の数 (ループ解消に使える)
    for (int i = 0; i < NUM; i++) {
        if (trans[i] == -1) {
            free_cnt++;
        }
    }
    cerr << "free_cnt: " << free_cnt << endl; // debug

    int self_loop_cnt = 0; // 自己ループの数
    for (int i = 0; i < NUM; i++) {
        if (trans[i] == i) {
            self_loop_cnt++;
        }
    }
    cerr << "self_loop_cnt: " << self_loop_cnt << endl; // debug

    int loop_cnt = 0; // ループの数(自己ループを含む)
    vector<bool> done(NUM);
    for (int i = 0; i < NUM; i++) {
        if (done[i]) {
            continue;
        }
        int tgt = i;
        set<int> st;
        while (tgt != -1) {
            if (done[i]) {
                break;
            }
            if (st.count(tgt)) {
                loop_cnt++;
                break;
            }
            st.insert(tgt);
            tgt = trans[tgt];
        }
        for (int s : st) {
            done[s] = true;
        }
    }
    cerr << "loop_cnt: " << loop_cnt << endl; // debug

    cout << (loop_cnt <= free_cnt ? NUM - free_cnt - self_loop_cnt + loop_cnt - self_loop_cnt: -1) << endl;
    return 0;
}
/*
何を何に変換しなければならないかのグラフを考えて…(2025/03/29 22:24:11)
変える順番を考慮するのよな。トポロジカル的な話が出てきそう(2025/03/29 22:24:40)
くそ，時間が足りないわ。(2025/03/29 22:24:45)

afbfda
bkckbb
a->b
f->k
b->c
d->b
---
b->c
a->b
f->k
d->b

abac
abrc

a->a
a->r
分岐すると駄目ね。自己ループの扱いは？(2025/03/29 22:26:55)

sample1の場合，a->bを実行することでb->bが生じて
b->bとb->cで分岐が生じると考えてもよいのかしら。いやできないパターンを考えても仕方ないのか。(2025/03/29 22:27:50)

abac
bcba
a->b
b->c
c->a
あー・・・
c->e
b->c
a->b
e->a
とすれば可能なのか…(2025/03/29 22:29:02)

ループを解消するのに1文字"消費"するから「ループの数<=空き文字の数」でないといけない。

a -> b -> c -> b というループだと？(2025/03/29 22:58:24)
c->e, b->c, a->b, e->b で無問題か。(2025/03/29 23:00:05)
*/
