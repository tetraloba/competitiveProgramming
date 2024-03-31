// 2024/03/31 08:07:33
// 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, a, b;
    cin >> N >> a >> b;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }
    sort(A.begin(), A.end());
    vector<long long> min_cs(N), max_cs(N); // cumulative sum
    min_cs[0] = A[1] - A[0];
    max_cs[N - 1] = A[N - 1] - A[N - 2];
    for (int i = 0; i < N - 1; i++) {
        min_cs[i] = min_cs[i - 1] + A[i + 1] - A[i];
    }
    for (int i = N - 2; 1 <= i; i--) {
        max_cs[i] = max_cs[i + 1] + A[i] - A[i - 1];
    }
    return 0;
}
/*
貪欲的に考えるならば、小さいものに足して大きいものから引いていく。
heapで最小値と最大値を取り続けてシミュレーション？間に合うかは不明。

3 2 3
11 1 2
が2になる

11 2 1
-1 -2 -11

11 1
あー片方には残るのか・・・・・
数を管理するmap作ってもよいが・・・・
前にも言った更新可能キューが欲しくなるのよね。

3 2 2
1 5 9

9 5 1
-1 -5 -9

9 1

3 2 3
11 1 2
11 2 1
-1 -2 -11
5
5
5 5 2
-2 -5 -5

あーだめだわ。毎回小さいやつを選び直して一回ずつ操作しなければ合わないのか。
ソートして、必要な操作回数を累積和的なので求めるのが正解な気がしてきた。(2024/03/31 08:33:02)

*/
