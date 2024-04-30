// 2024/04/30 18:59:41
// 2024/04/30 19:25:46 AC.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
long long N = 998244353;
int main(){
    int Q;
    cin >> Q;
    vector<long long> rems(Q + 1);
    rems[1] = 1;
    for (int i = 2; i <= Q; i++) {
        rems[i] = rems[i - 1] * 10 % N;
        // cout << i << ':' << rems[i] << endl; // debug
    }
    queue<int> que;
    que.push(1);
    long long rem = 1;
    for (int i = 0; i < Q; i++) {
        int q;
        cin >> q;
        switch (q) {
            case 1:
                int x;
                cin >> x;
                rem = (rem * 10 + x) % N;
                que.push(x);
                // cout << "rem:" << rem << endl; // debug
                break;
            case 2:
                // cout << "-:" << rems[que.size()] * que.front() << endl; // debug
                rem = ((rem + N * 10) - rems[que.size()] * que.front()) % N;
                que.pop();
                break;
            case 3:
                cout << rem << endl;
                break;
        }
    }
    return 0;
}
/*
1は簡単。10をかけてxを足して998244353で割っておけば良い。
問題は2だな。
10^1 ~ 10^(6*10^5)を998244353で割った値をメモしておくか？(2024/04/30 19:06:16)
*/
