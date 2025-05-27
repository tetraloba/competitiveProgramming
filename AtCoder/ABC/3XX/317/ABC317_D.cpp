// 2024/04/12 00:20:21
// 
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    int cnt = 0;
    vector<int> X(N), Y(N), Z(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i] >> Z[i];
        cnt += Z[i];
    }
    vector<int> cost(N);
    for (int i = 0; i < N; i++) {
        cost[i] = Y[i] - X[i];
        if (cost[i] < 0) {
            cost[i] = 0;
            cnt -= Z[i];
        }
        cout << cost[i] << ' ' << Z[i] << endl;
    }
    cout << cnt << endl;
    // cout <<  << endl;
    return 0;
}
/*
各選挙区についてdiff(X,Y)人動かせばZ議席動くってわけね。(2024/04/12 00:22:23)
つまり高々100個の(cost,performance)の情報から必要なperformanceを得るのに必要なcostの最小値を求める問題。(2024/04/12 00:24:44)
これって動的計画法とか使うやつかしら…(2024/04/12 00:26:48)
5 1
1 2
2 3
3 4
4 5
N=100, sum(Z)=10^5なので
O(N sum(Z))のO(10^7)で通りそうというメタ読み。(2024/04/12 00:59:59)
無理だ。寝ながら考えよう。(2024/04/12 01:09:45)
*/
/*
2024/04/12 12:14
動的計画法のナップサック問題だって。
動的計画法という勘はあっている。でも代表的な問題であるナップサック問題の解法を知らないのが問題。
というわけでお勉強しましょうね。
O(NS)のメタ読みも合っていたね(笑)
*/
