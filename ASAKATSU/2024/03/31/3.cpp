// 2024/03/31 08:07:33
// 
// ARC144_B - Gift Tax https://atcoder.jp/contests/arc144/tasks/arc144_b
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int main(){
    int N, a, b;
    cin >> N >> a >> b;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }
    map<int, int> cnt;
    priority_queue<int> MAX, MIN;
    for (int a : A) {
        MAX.push(a);
        MIN.push(-a);
        cnt[a]++;
    }
    while (true) {
        int max = MAX.top(); MAX.pop();
        while (cnt[max] == 0) {
            max = MAX.top(); MAX.pop();
        }
        cnt[max]--;
        int min = -MIN.top(); MIN.pop();
        while (cnt[min] == 0) {
            min = -MIN.top(); MIN.pop();
        }
        cnt[min]--;
        int num = (max - min) / (a + b);
        if (num <= 0) {
            break;
        }
        max -= b * num;
        min += a * num;
        MAX.push(max);
        cnt[max]++;
        MIN.push(-min);
        cnt[min]++;
    }
    cout << -MIN.top() << endl;
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
