// 2024/03/12 17:02:11
// 2024/03/12 18:11:28 25WA
// 2024/03/12 18:24:51 25WA
// 2024/03/12 19:10:17 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> X(M);
    for (int &x : X) {
        cin >> x;
        x--;
    }

    /* 各橋の重要性(閉鎖するとどれだけツアーの長さが増加するか)を求める。 O(M+N) */
    vector<long long> pass_weight_diff(N);
    for (int i = 0; i < M - 1; i++) {
        int dist = abs(X[i + 1] - X[i]);
        if (dist < N - dist) {
            /* N,1間を通らない*/
            pass_weight_diff[min(X[i], X[i + 1])] += N - dist - dist;
            pass_weight_diff[max(X[i], X[i + 1])] -= N - dist - dist;
            // cout << N - dist - dist << endl; // debug
        } else if (N - dist < dist) {
            /* N,1間を通る*/
            pass_weight_diff[max(X[i], X[i + 1])] += dist - (N - dist);
            pass_weight_diff[min(X[i], X[i + 1])] -= dist - (N - dist);
            // cout << dist - (N - dist) << endl; // debug
        } else {
            /* N,1間を通っても通らなくても同じ(橋を封鎖してもツアーの長さに影響しない) */
        }
    }
    // /* debug */
    // for (long long l : pass_num_diff) {
    //     cout << l << ' ';
    // }
    // cout << endl;

    vector<long long> pass_weight(N); // 橋iを通れない時の損害
    long long num = 0;
    for (int i = 0; i < N; i++) {
        num += pass_weight_diff[i];
        pass_weight[i] = num;
    }
    // /* debug */
    // for (int i : pass_num) {
    //     cout << i << ' ';
    // }
    // cout << endl;

    /* 封鎖する橋(closed_bridge)を決定する。 O(N) */
    int closed_bridge = min_element(pass_weight.begin(), pass_weight.end()) - pass_weight.begin(); // 封鎖する橋
    // cout << "closed_bridge:" << closed_bridge << endl; // debug

    /* closed_bridgeを閉鎖した時のツアーの長さを計算する。 O(M) */
    long long ans = 0;
    for (int i = 0; i < M - 1; i++) {
        int small = min(X[i], X[i + 1]);
        int large = max(X[i], X[i + 1]);
        int dist = large - small;
        if (dist < N - dist) {
            /* N,1間を通らない*/
            if (small <= closed_bridge && closed_bridge < large) {
                /* closed_bridgeを通る */
                ans += N - dist;
            } else {
                /* closed_bridgeを通らない */
                ans += dist;
            }
        } else if (N - dist < dist) {
            /* N,1間を通る*/
            if (closed_bridge < small || large <= closed_bridge) {
                /* closed_bridgeを通る */
                ans += dist;
            } else {
                /* closed_bridgeを通らない */
                ans += N - dist;
            }
        } else {
            /* N,1間を通っても通らなくても同じ */
            ans += dist;
        }
        // cout << ans << ','; // debug
    }
    // cout << endl; // debug

    cout << ans << endl;

    return 0;
}
/*
N個の橋を全探索するとして、それぞれでのツアーの長さを如何に高速に計算するかだな。
メモ化とか累積和的なものが使えそうだけれど… (2024/03/12 17:08:17)
封鎖するとどうなる？
そこを通ったほうが早かった移動t(t < N / 2)がN - tになる？
そもそも島移動の長さはmin(|A - B|, N - |A - B|)
一番通る回数の少ない橋を落とせば良いのか。 (2024/03/12 17:17:31)
距離が同じ(N=偶数の反対側)場合の処理が分からん… (2024/03/12 17:20:27)
1 2
4 3
1 2 4 3 2 とかだと1-4を落とすべきだけれど…
両方に足しちゃっても良いのかな。

1 2 1 4 3 2
12,12,41,23,34,34,23
一番少ないのは4-1
でこれをカッコの組みたいな感じで上手く高速に処理しないとな。O(N+M)に落とせるはず。 (2024/03/12 17:25:44)
12,24,42,34,23
12,24,41,12,34,23
12,12,23,24,34,41 O(M)
+2,0,0,-1
2,2,2,1 O(N)

全然駄目。5AC 25WA
Sample通ってしまうのがなあ…
最短経路で動いた場合の橋を通る回数を求めるO(M+N) => 通る回数が最も少ない橋を封鎖するO(N) => 封鎖した時のツアーの長さを計算するO(M)
の流れで駄目なのかなあ…
通る回数が少ないことと封鎖する最適解であることが異なるのか？ (2024/03/12 18:16:23)
まあ通る回数は多いけど距離への影響は少ないってことは有るか。
1~100で 1 49 1 49 1 49 1 49 50 100 1 みたいな場合、49-50間は1回しか通らないけど、封鎖すると49->50が1から100になるもんな。
重みを乗せるか～？ (2024/03/12 18:20:52)
割とマジでそれが正解な気がするな。 (2024/03/12 18:21:39)
↑何も変わりませんでしたごめんなさい (2024/03/12 18:25:23)

100 12
1 49 1 49 1 49 1 49 50 75 100 1

10 12
1 4 1 4 1 4 1 4 5 7 10 1
10 11
1 4 1 4 1 4 1 4 5 7 10
10 8
1 4 1 4 5 7 10 1

テストケースが不足しているので全探索して妥当性チェックを行うなど。
```
    long long min = 100000000;
    int min_i;
    for (int closed_bridge = 0; closed_bridge < N; closed_bridge++) {
        long long ans = 0;
        for (int i = 0; i < M - 1; i++) {
            int dist = abs(X[i + 1] - X[i]);
            if (dist < N - dist) {
                if (X[i] <= closed_bridge && closed_bridge < X[i + 1]) {
                    ans += N - dist;
                } else {
                    ans += dist;
                }
            } else if (N - dist < dist) {
                if (closed_bridge < X[i] || X[i + 1] <= closed_bridge) {
                    ans += dist;
                } else {
                    ans += N - dist;
                }
            } else {
                ans += dist;
            }
        }
        if (ans < min) {
            min = ans;
            min_i = closed_bridge;
        }
    }
    cout << min_i << ':' << min << endl;
```

10 12
1 4 1 4 1 4 1 4 5 7 10 1
7を切った時
3+3+3+3+3+3+3+1+2+7+1 = 32
10を切った時
3+3+3+3+3+3+3+1+2+3+9 = 36

長さの計算が間違っているのか。10->1の時に距離9になっているわ。(2024/03/12 19:08:19)

*/
/*
↑のミスのせいで隠れていたが、「重みを乗せるか～？」付近の考察も正しいね。
重み無しで通過する回数だけにすると9AC 21WAだわ。

> N個の橋を全探索するとして、それぞれでのツアーの長さを如何に高速に計算するかだな。
> メモ化とか累積和的なものが使えそうだけれど… (2024/03/12 17:08:17)
まあ、良い勘はしているよね。
確か当初はO(N log M)に落とし込むつもりだったんだけどね。
> 一番通る回数の少ない橋を落とせば良いのか。 (2024/03/12 17:17:31)

> でこれをカッコの組みたいな感じで上手く高速に処理しないとな。O(N+M)に落とせるはず。 (2024/03/12 17:25:44)
「カッコの組みたいな感じ」とか良くわからないこと言っているけどこれがいもす法(imos法)のことね(笑)
*/
