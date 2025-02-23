// 2025/02/23 10:16:23
// 2025/02/23 10:37:57 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int Q;
    cin >> Q;
    long long out = 0; // 抜けたヘビの長さの合計値
    vector<int> ls(1, 0); // i番目のヘビの長さ
    vector<long long> ps(1, 0); // i番目のヘビの頭の座標(最初のヘビの頭が0)
    int index = 1; // 何番目に追加されたか
    int head = 1; // 現在の先頭のindex
    for (int q = 0; q < Q; q++) {
        int query;
        cin >> query;
        switch (query) {
            case 1:
                int l;
                cin >> l;
                ps.push_back(ps.back() + ls.back());
                ls.push_back(l);
                break;
            case 2:
                out += ls[head];
                head++;
                break;
            case 3:
                int k;
                cin >> k;
                cout << ps[head + k - 1] - out << endl;
                break;
        }
        /* debug */
        // for (auto l : ls) {
        //     cerr << l << ' ';
        // }
        // cerr << endl;
        // for (auto p : ps) {
        //     cerr << p << ' ';
        // }
        // cerr << endl;
    }
    return 0;
}
/*
抜けたヘビの合計値を引けばよいのか。(2025/02/23 10:19:35)
*/
/*
outは無くてもps[head]とls[head]から計算可能か。(2025/02/23 10:40:02)
*/
