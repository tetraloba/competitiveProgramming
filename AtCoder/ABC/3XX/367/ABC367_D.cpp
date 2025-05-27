// 2025/03/13 09:23:30
// 2025/03/13 11:54:03 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
        a %= M;
    }
    vector<int> dist_from_0(2 * N);
    for (int i = 1; i < 2 * N; i++) {
        dist_from_0[i] = (dist_from_0[i - 1] + A[(i - 1) % N]) % M;
    }

    /* debug */
    // cerr << "dist_from_0: ";
    // for (int i : dist_from_0) {
    //     cerr << i << ' ';
    // }
    // cerr << endl;

    int l = 1, r = N; // 休憩所l-1から 休憩所l, l+2, ... , (0, 1, 2,) ... , r-1まで
    vector<int> dist_modMs(M); // 休憩所 l ~ r-1 の内，休憩所l-1からの距離%M が dist_modMs_begin + i であるものの数
    int dist_modMs_begin = 0; // dist_modMsの始点
    for (int i = l; i < r; i++) {
        dist_modMs[dist_from_0[i] % M]++;
    }

    /* debug */
    // for (int i : dist_modMs) {
    //     cerr << i << ' ';
    // }
    // cerr << endl;

    long long ans = dist_modMs[dist_modMs_begin];
    for (int i = 1; i < N; i++) {
        dist_modMs[dist_from_0[l]]--;
        // cerr << dist_from_0[l] << " --" << endl; // debug
        l++;
        dist_modMs[dist_from_0[r]]++;
        // cerr << dist_from_0[r] << " ++" << endl; // debug
        r++;

        /* debug */
        // for (int m = 0; m < M; m++) {
        //     cerr << dist_modMs[(dist_modMs_begin + m) % M] << ' ';
        // }
        // cerr << " -> ";

        dist_modMs_begin = dist_from_0[l - 1] % M;

        /* debug */
        // for (int m = 0; m < M; m++) {
        //     cerr << dist_modMs[(dist_modMs_begin + m) % M] << ' ';
        // }
        // cerr << endl;

        ans += dist_modMs[dist_modMs_begin];
    }

    cout << ans << endl;
    return 0;
}
/*
これ，知ってる知識で解けるのかなあ・・・
剰余系の知識が必要そうな気もするのだけれど。%Mじゃなくて偶奇ならやったことある気もするが。(2025/03/13 09:29:59)
とりあえず始点固定の部分問題から考えてみるか。(2025/03/13 09:30:30)
# 14 # 22 # 12
%5
# 4 # 2 # 2
#(0) #(4) #(1) #(3)(0) 
ループは2周分考えれば良いのかしら。(2025/03/13 09:40:21)
sample 1
2 1 4 3 | 2 1 4 3
2 1 1 0 | 2 1 1 0
2 0 1 1 | 0 1 2 2 from 1
X 1 2 2 1 | 2 0 0 from 2
X X 1 1 0 1 | 2 2 from 3
X X X 0 2 0 1 | 1 from 4
X X X X 2 0 1 1 |
差分は一定だから全部更新する必要はないのか。やはり%Mで集計するのが正解そう(2025/03/13 09:58:04)
%M 0 1 2
   1 1 1 from 1
   0 1 2 from 2
   1 2 0 from 3
   2 0 1 from 4

   1 1 1 -> 1 2 0 (-2)
   0 1 2 -> 0 1 2 (-1)
   1 2 0 -> 1 2 0 (-1)
   2 0 1
だから1つ減らす，1つ増やす，ズラす，の操作をO(1)でできるわけね。(2025/03/13 10:03:38)
実装やや面倒だな。(2025/03/13 10:04:35)

sample3
9 9 8 2 4 4 3 5 3 | 9 9 8 2 4 4 3 5 3
4 4 3 2 4 4 3 0 3 | 4 4 3 2 4 4 3 0 3
4 3 1 3 2 1 4 4 2 | 1 0 3 0 4 3 1 1 4 from 1
X 4 2 4 3 2 0 0 3 2 | 1 4 1 0 4 2 2 0 from 2
X X 3 0 4 3 1 1 4 3 2 | 0 2 1 0 3 3 1 from 3
...

0 2 1 2 3
0 2 2 2 2
0 3 2 1 2
*/
