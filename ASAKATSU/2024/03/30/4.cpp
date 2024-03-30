// 2024/03/30 08:22:46
// 2024/03/30 10:26:01 AC.
#include <iostream>
#include <vector>
#define MOD 998244353
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int &a : A) {
        cin >> a;
    }
    for (int &b : B) {
        cin >> b;
    }
    vector<vector<long long>> vv(N, vector<long long>(3001));
    long long min = A[0] < B[0] ? A[0] : B[0];
    long long max = A[0] < B[0] ? B[0] : A[0];
    for (int i = min; i <= max; i++) {
        vv[0][i] = 1;
    }
    for (int i = 1; i < N; i++) {
        long long min = A[i] < B[i] ? A[i] : B[i];
        long long max = A[i] < B[i] ? B[i] : A[i];
        long long sum = 0;
        for (int j = 0; j <= max; j++) {
            sum += vv[i - 1][j];
            sum %= MOD;
            if (min <= j) {
                vv[i][j] = sum;
            }
        }
    }
    // /* debug */
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < 100; j++) {
    //         cout << vv[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    long long ans = 0;
    for (long long i : vv[N - 1]) {
        ans += i;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
/*
1 10 100
3 8 80
2 9 
可能だろうけれど面倒くさいな(2024/03/30 08:32:10)
再開(2024/03/30 09:18:40)
10
1 2 3  4  5  6  7  8  9  10
1 4 9 16 25 36 49 64 81 100

(1,2), (1,3) | (1,4)
直前の数だけ見ればよいのは分かる。
(1,2), (1,3) -> 3~4, 5~9
(1,4) -> 4, 5~9
4~5, 5~16
9~16
あーわけわからなくなってきた
最初は1のみ
2: 2~4
3: 2~
preの上限よりもnowの下限が小さい場合の問題
preの上限以上はかけるだけ。
3 4
9 16
3~4のとき 16-4通り
4~9のとき 16-now
9~16のとき 16-9 通り
これを実装するだけ。(2024/03/30 09:33:46)
4   5
16 25
あー3000だから出てくる数字の全探索は可能なのか。(2024/03/30 09:39:42)
3000x3000の配列作るのが楽そう。
洗濯終わり。再開(2024/03/30 09:54:07)
*/
/*
「n番目の数がXになる場合の数は、n-1番目の数がX以下の数になる場合の数の合計に等しい。」
制約が3000と緩いので、3000x3000の配列を作って実装すれば良い。
*/
