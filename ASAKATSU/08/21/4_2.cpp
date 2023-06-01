//2022/08/21 07:48:35
//2022/08/21 08:24:25 WA TLE RE
//2022-08-21 08:29:32 TLE RE とりあえずxのオーバフローは直したが…
//ABC241_D - Sequence Query
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int main(){
    int Q;
    cin >> Q;
    vector<long long> A;
    for (int i = 0; i < Q; i++) {
        int c, k;
        long long x;
        cin >> c >> x;
        if (c == 1) {
            A.push_back(x);
            sort(A.begin(), A.end());
            // for (auto i : A) { //debug
            //     cout << i << ' ';
            // }
            // cout << endl;
        } else { 
            cin >> k;
            auto itr = A.begin();
            bool flag = true;
            if (c == 2) {
                if (x < *itr) {
                    flag = false;
                }
                if (flag) { //elseでもええけどc==3に合わせて。
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
//↑変わらんな。
//解説読んだ。やはりc==2,c==3の最初のwhileによる線形探索(O(N))が遅すぎるんだな。
//upper_boundとlower_boundを覚えるのは良いとして、いい加減二分探索覚えましょう。