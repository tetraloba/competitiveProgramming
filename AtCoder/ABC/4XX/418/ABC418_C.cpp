// 2025/12/22 13:06:19
// 2025/12/22 15:07:52 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    vector<int> B(Q);
    for (int &a : A) {
        cin >> a;
    }
    for (int &b : B) {
        cin >> b;
    }

    sort(A.begin(), A.end());
    vector<long long> prefix(N + 1);
    for (int i = 0; i < N; i++) {
        prefix[i + 1] = A[i] + prefix[i];
    }
    
    for (int b : B) {
        auto itr = lower_bound(A.begin(), A.end(), b);
        if (itr == A.end()) {
            cout << -1 << endl;
            continue;
        }
        cout << prefix[itr - A.begin()] + (long long)(b - 1) * (N - (itr - A.begin())) + 1 << endl;
    }

    return 0;
}
/*
2025/12/22 13:21:09
ディーラーはラウンドロビンしてくると思えばよいわけね。
2025/12/22 13:23:43
まあ、ソートして累積和的なものを作っておけば間に合うか。
2025/12/22 13:25:16
やろうと思えばBj全部作れるか？
2025/12/22 13:30:06
「tgtより小さいやつまでの累積和 + (tgt-1)×tgt以上の数+1」か。
2025/12/22 15:04:23再開。
*/
