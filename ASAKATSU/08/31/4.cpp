//2022/08/31 07:39:27
//
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    map<int, int> mp;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 1; j * j <= A[i]; j++) {
            if (!(A[i] % j)) {
                mp[j]++;
                if (j * j != A[i]) {
                    mp[A[i] / j]++;
                }
            }
        }
    }
    for (auto i: mp) {
        cout << i.first << ':' << i.second << endl;
    }
    for (int i = 0; i < N; i++) {
        cout << A[i] << ' ' << mp[A[i]] << endl;
        // cnt += mp[A[i]];
        if (mp[A[i]] <= 1) {
            cnt++;
        }
        cout << "cnt = " << cnt << endl;
    }
    cout << cnt << endl;
    return 0;
}
//sortしたら自分より大きいやつからは絶対に割り切れないが…？そういう問題じゃないよな。
//素因数分解、でもないか？
//効率化という意味では累積和的なやつかなと思うんだけど分からんな。
// 24 11 8 3 16
// 素因数分解してMapに蓄積していくか。
//素因数分解と言うより正確には約数書き出し。
//約数書き出し時間がかかるし、間に合わない気がするな。2022/08/31 07:50:06