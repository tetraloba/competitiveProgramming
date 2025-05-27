// 2024/07/28 18:49:55
// 2024/07/28 19:01:49 TLE
// 2024/07/28 19:10:37 RE
// 2024/07/28 19:11:39 AC.
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }
    int M;
    cin >> M;
    set<int> B;
    for (int i = 0; i < M; i++) {
        int b;
        cin >> b;
        B.insert(b);
    }
    int X;
    cin >> X;

    vector<bool> can_reach(X+1);
    can_reach[0] = true;
    for (int i = 0; i < X + 1; i++) {
        if (!can_reach[i]) {
            continue;
        }
        if (B.count(i)) {
            continue;
        }
        for (int a : A) {
            if (X < i + a) {
                continue;
            }
            can_reach[i + a] = true;
        }
    }
    cout << (can_reach[X] ? "Yes" : "No") << endl;
    return 0;
}
/*
Nが小さいので動的計画法で解けるかな。(2024/07/28 18:54:09)
*/
/*
普通に実装間違えたよね。やはりDPのやり方よく分かっていないなあ。
*/
