// 2024/02/26 12:32:12
// 
#include <iostream>
#include <vector>
#include <algorithm>
#define NUM 998244353
using namespace std;
// N!
long long bikkuri(long long N){
    long long ans = 1;
    while (N) {
        ans *= N--;
        ans %= NUM;
    }
    return ans;
}
int main(){
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> v;
    for (int i = 0; i < N; i++) {
        v.push_back(0);
    }
    for (int i = 0; i < M - 1; i++) {
        v.push_back(1);
    }
    long long ans = 0;
    long long Nbikkuri = bikkuri(N);
    do {
        vector<int> M_nums(M);
        int i = 0;
        for (int j : v) {
            if (j) {
                i++;
            } else {
                M_nums[i]++;
            }
        }
        long long sum = 0;
        for (int j = 0; j < M; j++) {
            sum += (j + 1) * M_nums[j];
        }
        // // debug
        // for (int m : M_nums) {
        //     cout << m << ' ';
        // }
        // cout << sum << endl;

        int ans_tmp = 0;
        if (sum <= K) {
            ans_tmp++;
        }
        long long narabekae = Nbikkuri;
        for (int m : M_nums) {
            if (1 <= m) {
                narabekae /= m;
            }
        }
        ans += ans_tmp * narabekae % NUM;
        ans %= NUM;
    } while (next_permutation(v.begin(), v.end()));

    cout << ans << endl;
    return 0;
}
// N個のM以下 の総和が K以下
// 2500 - 50 = 2450
// (2450 + (50 - 1)) C (50 - 1)
// ((K - N) + (N - 1)) C (N - 1)
// いや、１枠あたりの上限個数が有るから駄目か。
// 数だけ分かれば良いから、50(M)種の数字に50(N)個の玉を振り分ければよいのか。天才。 (2024/02/26 12:49:55)
// N個の玉とM - 1個の仕切りを並べ替える (N + M - 1) C N 通り
// 後は順列のnext_permutation()かな。久しぶりに使うな。ググろ。
// 1~6 が 3つのとき ooo|||||
// いや違うじゃん。数の組じゃなくて数列じゃん。順番区別するじゃん。アホすぎ。 (2024/02/26 13:12:58)
// いやそれは後から計算すれば良いかな。
// (速度的に)無理があろうと思われます
