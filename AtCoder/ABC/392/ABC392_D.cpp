// 2025/02/24 10:13:43
// 2025/02/24 10:55:04 AC.
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
double probability(vector<int>& v1, vector<int>& v2){
    double res = 0;
    // int same_cnt1 = 0, same_cnt2 = 0;
    auto itr1 = v1.begin(), itr2 = v2.begin();
    while (itr1 != v1.end() && itr2 != v2.end()) {
        int tgt = max(*itr1, *itr2);
        while (itr1 != v1.end() && *itr1 < tgt) {
            itr1++;
        }
        while (itr2 != v2.end() && *itr2 < tgt) {
            itr2++;
        }
        int cnt1 = 0, cnt2 = 0;
        while (itr1 != v1.end() && *itr1 == tgt) {
            itr1++;
            cnt1++;
        }
        while (itr2 != v2.end() && *itr2 == tgt) {
            itr2++;
            cnt2++;
        }
        res += (double)cnt1 / v1.size() * cnt2 / v2.size();
        // if (0 < cnt1 && 0 < cnt2) {
        //     same_cnt1 += cnt1;
        //     same_cnt2 += cnt2;
        // }
    }
    // cerr << same_cnt1 << ' ' << same_cnt2 << endl;
    // return (double)same_cnt1 / v1.size() * same_cnt2 / v2.size();
    return res;
}
int main(){
    int N;
    cin >> N;
    vector<vector<int>> A(N);
    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;
        vector<int> v(K);
        for (int &a : v) {
            cin >> a;
        }
        sort(v.begin(), v.end());
        A[i] = v;
    }
    double ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            double prob = probability(A[i], A[j]);
            // cerr << setprecision(5) << i << ' ' << j << ' ' << prob << endl; // debug
            ans = max(ans, prob);
        }
    }
    cout << setprecision(10) << ans << endl;
    return 0;
}
/*
目の種類は何通り？(2025/02/24 10:17:25)
制約3より，(1+446) * 446 / 2 = 99681
446通りか。(2025/02/24 10:20:17)
組み合わせの数は100C2 = 4950 (2025/02/24 10:25:02)
いやKが小さければ446通り以上有るのか・・・(2025/02/24 10:28:13)

各目について，各サイコロ(その目が有るもののみ)で出る確率を求めておいて，組み合わせ毎に足していけば？計算量解析できないけど(2025/02/24 10:31:10)
それなら組み合わせで，目をソートしておけばO((K+K) * NC2)でいけるのでは。(2025/02/24 10:33:31)
*/

