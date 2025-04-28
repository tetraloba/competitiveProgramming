// 2025/04/28 09:57:01
// 2025/04/28 10:06:07 AC.
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }

    multiset<int> mst(A.begin(), A.end());
    for (int i = 0; i < M; i++) {
        int tgt = *mst.rbegin();
        mst.erase(mst.find(tgt));
        mst.insert(tgt / 2);
    }
    long long ans = 0;
    for (int i : mst) {
        ans += i;
    }
    cout << ans << endl;
    return 0;
}
/*
順番はどうでも良いのでソートするとして、でかいやつから2で割っていけばよいわけだが…(2025/04/28 09:59:43)
*/
