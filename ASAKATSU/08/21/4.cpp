//2022/08/21 07:48:35
//2022/08/21 08:24:25 WA TLE RE
//2022-08-21 08:29:32 TLE RE とりあえずxのオーバフローは直したが…
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int main(){
    int Q;
    cin >> Q;
    multiset<long long> A;
    for (int i = 0; i < Q; i++) {
        int c, k;
        long long x;
        cin >> c >> x;
        if (c == 1) {
            A.insert(x);
            // for (auto i : A) { //debug
            //     cout << i << ' ';
            // }
            // cout << endl;
        } else { 
            cin >> k;
            auto itr = A.begin();
            bool flag = true;
            if (c == 2) {
                while (*itr <= x && itr != A.end()) {
                    itr++;
                }
                itr--; //最大の「x以下の値」を指す
                for (int i = 0; i < k - 1; i++) {
                    if (itr == A.begin()) {
                        flag = false;
                        break;
                    }
                    itr--;
                }
            } else {
                while (*itr < x) { //最小の「x以上の値」を指す
                    if (itr == --A.end()) {
                        flag == false;
                        break;
                    }
                    itr++;
                }
                if (flag) {
                    for (int i = 0; i < k - 1; i++) {
                        if (itr == --A.end()) {
                            flag = false;
                            break;
                        }
                        itr++;
                    }
                }
            }
            cout << (flag ? *itr : -1) << endl;
        }
    }
    return 0;
}
//WAはオーバフロー
//REはイテレータでなにか間違っている
//TLEはmultisetではなくシーケンシャルコンテナを使うべきかな。vectorでsortするほうが良さそう。