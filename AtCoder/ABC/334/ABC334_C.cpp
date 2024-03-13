// 2024/03/13 20:26:49
// 2024/03/13 20:58:35 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    vector<int> A(K);
    vector<int> sum_l(K), sum_r(K);
    for (int &a : A) {
        cin >> a;
    }
    for (int i = 1; i < K; i++) {
        if (i % 2) {
            sum_l[i] = sum_l[i - 1] + (A[i] - A[i - 1]);
        } else {
            sum_l[i] = sum_l[i - 1];
        }
    }
    for (int i = K - 1; 0 <= i; i--) {
        if (i % 2) {
            sum_r[i] = sum_r[i + 1] + (A[i + 1] - A[i]);
        } else {
            sum_r[i] = sum_r[i + 1];
        }
    }
    // /* debug */
    // for (int i : sum_l) {
    //     cout << i << ' ';
    // }
    // cout << endl;
    // for (int i : sum_r) {
    //     cout << i << ' ';
    // }
    // cout << endl;

    vector<int> sum(K);
    for (int i = 0; i < K; i++) {
        sum[i] = sum_l[i] + sum_r[i];
    }

    if (K % 2) {
        cout << *min_element(sum.begin(), sum.end()) << endl;
    } else {
        cout << sum_l[K - 1] << endl;
    }
    // cout <<  << endl;
    return 0;
}
/*
1 2 3 4

1 2 4 7 8
1 2 3 3 4 5 5 6 6 7 8
1 2 4 7 8 => (1,2), (7,8), 4

4 5 5 6 6 7 7 8 みたいな場合って
(4,5), (5,6), (6,7), (7,8) で4にしても
(4,8), 55 66 77 で4にしても同じだよな…
同じ靴下の組を敢えて分けた方が良いケースを思いつかない。

1 4 5 9 は？
3 + 4 = 7
1 + 8 = 9
差分をa,b,cとして
a+b+c + b か a + c だから後者のほうが良いのは明白か。

問題は奇数の場合のみ。
どれを捨てればよいかは全探索O(N^2)だと間に合わないか。
左右からの累積和的なので行けそう。

1 2 4 7 8
0 1 1 4 4
3 3 1 1 0
*/
