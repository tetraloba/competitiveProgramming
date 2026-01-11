// 2026/01/11 14:36:18
// 2026/01/11 14:53:32 16/49 WA
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, X, Y;
    cin >> N >> X >> Y;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }

    sort(A.begin(), A.end());
    vector<int> W(N);
    for (int i = 0; i < N; i++) {
        W[i] = (long long)A[i] * Y;
    }

    long long ans = 0;
    for (int a : A) {
        ans += a;
    }
    for (int i = N - 1; 0 < i; i--) {
        long long d = W[i] - W[0];
        if (d % (Y - X)) {
            ans = -1;
            break;
        }
        long long small_num = d / (Y - X);
        if (A[i] < small_num) {
            ans = -1;
            break;
        }
        ans -= small_num;
    }

    cout << ans << endl;
    return 0;
}
/*
a_i X + b_i Y = K
a_i + b_i = A_i
2026/01/11 14:41:54
11 88
10 80
13 104
これを2ずつ減らしていくだけか。
難しいのはどういうパターンだ？
3 12
5 20
1ずつ減らすが8減らせないので駄目、か。
2026/01/11 14:43:30
5 7
11 77
10 70
13 91
これだと無理なのか？
2026/01/11 14:46:29
最小個数のやつは絶対に全部大きいアメ、で良いのかなあ？


*/
/*
2026/01/11 15:14:51
解説見たけどよく分からないっぴ。
「最小個数のやつは絶対に全部大きいアメ」は何故駄目なのだろう。
全部Yの状態から、Y-Xずつしか動かせないのだから、最小の人を動かす意味はない気がするのだけれど。
*/

