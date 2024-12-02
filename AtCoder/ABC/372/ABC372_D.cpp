// 2024/12/02 12:56:55
// 2024/12/02 15:34:52 WA
// 2024/12/02 16:10:45 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using Cell = pair<int, int>;
class Sstack{ // searchable stack
    private:
        vector<Cell> *_stk;
        int _size = 0;
    public:
        Sstack(int N);
        ~Sstack();
        vector<Cell>::iterator ub(Cell);
        int ubi(Cell);
        void push(Cell);
        void debug();
};
Sstack::Sstack(int N){
    _stk = new vector<Cell>(N + 1);
    (*_stk)[N] = {N + 1, N};
}
Sstack::~Sstack(){
    delete this->_stk;
}
vector<Cell>::iterator Sstack::ub(Cell tgt){ // upper bound
    return upper_bound(_stk->end() - 1 - _size, _stk->end(), tgt);
}
int Sstack::ubi(Cell tgt){ // upper bound index
    return ub(tgt)->second;
}
void Sstack::push(Cell v){
    int idx = ub(v) - _stk->begin();
    idx--;
    // cerr << v.first << ',' << v.second << ':' << idx << endl; // debug
    (*_stk)[idx] = v;
    _size = _stk->size() - idx - 1;
}
void Sstack::debug(){
    for (auto s : *_stk) {
        cerr << '(' << s.first << ',' << s.second << ')' << ' ';
    }
    cerr << "size(" << _size << ")";
    cerr << endl;
}

int main(){
    /* input */
    int N;
    cin >> N;
    vector<int> H(N);
    for (int &h : H) {
        cin >> h;
    }

    /* process */
    Sstack stk(N); // stack
    stk.push({H[N - 1], N - 1});
    // stk.debug(); // debug
    vector<int> ans(N);
    for (int i = N - 2; 0 <= i; i--) {
        // cerr << "upper index: " << H[i + 1] << ':' << stk.ubi({H[i + 1], 0}) << endl; // debug
        ans[i] = ans[stk.ubi({H[i + 1], i + 1}) - 1] + 1;
        stk.push({H[i], i});
        // stk.debug(); // debug
    }

    /* output */
    for (int i = 0; i < N; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;

    return 0;
}
/*
左からmax()を見ていったときに変化する部分の数ってことかな。(2024/12/02 12:58:40)
↑それだとiより大きい物の数か？それですらないか・・・(2024/12/02 13:10:21)
いずれにしても右から求めるほうが求まりやすそう(2024/12/02 13:15:33)

9 7 5 3 1 2 4 6 8 10
自分より右で、一番左にいる自分より大きいやつを高速で見つけられれば良い。(2024/12/02 13:56:59)
それが分かればそいつの値+1で簡単に計算できる。
あーなるほど、昇順になるものだけリストに入れて、二分探索すれば良いのか。(2024/12/02 13:59:16)
上のやつだと
10
10 8
10 8 6
10 8 6 4
10 8 6 4 2
10 8 6 4 2 1
10 8 6 4 3
10 8 6 5
10 8 7
10 9
10
と動く。
sample2だと
4
4 3
4 3 2
4 3 2 1
sample3だと
3
8
8 4
10
10 7
10 7 2
10 7 5
10 7 6
10 9

*/
/*
解説を読んで。
あそっかあ、二分探索しなくて良いんだｗｗｗ
自分でStackって書いておきながら何故気づかないｗｗ
制約的にO(N log N)で決め打ちしたのが仇になったな。
いや違うな。スタックに大量に詰まっていたらオーダー悪くなると思ったんだよな。
実際にはスタックの出し入れが最大N回しか行われないから高々O(N)にしかならないって話。
計算量が身についていない。
*/

