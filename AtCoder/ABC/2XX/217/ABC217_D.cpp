//2022/08/21 18:06:29
//2022/08/21 18:40:24 TLE
#include <iostream>
#include <vector>
#include <list>
using namespace std;
int main(){
    int L, Q;
    cin >> L >> Q;
    list<int> ls;
    ls.push_front(L);
    for (int i = 0; i < Q; i++) {
        int c, x;
        cin >> c >> x;
        auto itr = ls.begin();
        if (c == 1) {
            int sum = 0;
            while (sum < x) {
                sum += *itr;
                itr++;
            }
            int tmp = sum - x;
            ls.insert(itr, tmp);
            // cout << "*itr:" << *itr << endl; //debug
            itr--;
            itr--; //insertはitrの前に要素を挿入するので元のitrの一つ前の要素に戻るには2回itr--;
            *itr -= tmp;
            // cout << "*itr:" << *itr << endl; //debug
            // for (int i : ls) { //debug
            //     cout << i << ' ';
            // }
            // cout << endl;
        } else {
            int sum = 0;
            while (sum < x) {
                sum += *itr;
                itr++;
            }
            itr--;
            cout << *itr << endl;
        }
    }
    return 0;
}
//基本はリスト構造だよな。
//長さと累積和の２つのリスト？累積和はいらんか…
//リスト構造のシーケンシャルアクセスだとまずいのかしら？
//TLE
//よく見たらクエリ20万回もあるのね。20万回切られたら流石にシーケンシャルアクセスで前から場所探すのでは間に合わんな。
//これvectorで良くね() vectorのinsertだと遅いのかしら。
//あと累積和のvectorも作って二分探索したいけど、元がシーケンシャルアクセスだと意味ないんだよなあ… 2022/08/21 18:44:36
//2022/08/21 18:47:50 解説読んだ
//平衡二分探索木やB-Tree…それっぽいワード出てきたけど分からねえ…
//え、もしかしてむしろ累積和だけで十分…？
//やな。累積和だけのほうが勝手が良い。2022/08/21 18:53:30