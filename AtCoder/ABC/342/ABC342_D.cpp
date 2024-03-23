// 2024/03/23 19:44:44
// 2024/03/23 20:07:42 13WA
// 2024/03/23 20:14:50 11WA
// 2024/03/23 20:21:52 AC.
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }

    for (int &a : A) {
        if (!a) {
            continue;
        }
        for (int i = 2; i * i <= 200000; i++) { // O(447)
            while (a % (i * i) == 0) {
                a /= i * i;
            }
        }
    }

    map<int, int> cnt;
    for (int a : A) {
        cnt[a]++;
    }

    long long ans = 0;
    for (auto [k, v] : cnt) {
        // cout << k << ' ' << v << ' ' << (long long)(1 + v - 1) * (v - 1) / 2 << endl;
        ans += (long long)(1 + v - 1) * (v - 1) / 2;
        if (!k) {
            ans += (long long)(N - v) * v;
        }
    }

    cout << ans << endl;
    return 0;
}
/*
素因数分解しておいて素因数の和が偶数なら…だけど？(2024/03/23 19:47:34)
0は例外ね。
いずれにしてもO(NC2)(=O(N^2))が間に合わないのが問題か。
0 3 2 8 12 平方数(非0)で割ると
0 3 2 2 3 と同じか。

2 2 4 6 3 100 100 25
2 2 1 6 3 1 1 1

平方数で割っておいて、同じ数値になる組み合わせの数。(2024/03/23 19:55:03)

*/
