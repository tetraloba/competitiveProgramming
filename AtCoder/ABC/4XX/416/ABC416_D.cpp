// 2025/12/14 02:30:28
// 2025/12/14 03:04:16 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N, M;
        cin >> N >> M;
        vector<int> A(N), B(N);
        for (int &a : A) {
            cin >> a;
        }
        for (int &b : B) {
            cin >> b;
        }

        long long sum = 0;
        for (int i = 0; i < N; i++) {
            sum += A[i] + B[i];
        }
        sort(A.rbegin(), A.rend());
        sort(B.begin(), B.end());
        int cnt_over_M = 0;
        auto itr = B.begin();
        for (int i = 0; i < N; i++) {
            itr = lower_bound(itr, B.end(), M - A[i]);
            if (itr == B.end()) {
                break;
            }
            cnt_over_M++;
            itr++;
            if (itr == B.end()) {
                break;
            }
        }
        cout << sum - (long long)M * cnt_over_M << endl;
    }
    return 0;
}
/*
2025/12/14 02:44:25
順列全探索だからDPではないし…
Ai + Bi ができるだけM以上になるようにすることで、\sum{Ai} + \sum{Bi}から削減していこうみたいなこと？
降順ソートすれば良いって話でもないよね。
5 6
5 4 3 2 1
5 4 3 1 1 よりも
5 4 3 2 1
1 2 3 4 5 の方が良いし
2025/12/14 02:48:11
sortして貪欲かなあ・・・
\sum|Ai - Bi|を最小化するみたいな問題あるよなあ。解けるんだっけ？
2025/12/14 02:51:33
Ai + Bi < M ならどのような組み合わせでも同じだし、Ai + Bi < 2M だから
Aを降順ソートして、Bを昇順ソートして、
M - Ai <= Bj となる最小のjを二分探索して、あとは適当に、か。
*/
/*
2025/12/14 03:07:06
解説を読んで。
基本的な発想はあっている。
なるほど、Bはどうせ一回しか探索しないから(二分探索せずに)頭から追い上げていけばO(N)か。
*/
