// 2024/02/28 19:11:06
// 2024/02/28 19:19:38 ラーメン食べる
// 2024/02/28 19:?? 復帰
// 2024/02/28 20:03:52 WA いつものlong long
// 2024/02/28 20:12:30 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using LL = long long;
int main(){
    int N, M, P;
    cin >> N >> M >> P;
    vector<int> A(N), B(M);
    for (int &a : A) {
        cin >> a;
    }
    for (int &b : B) {
        cin >> b;
    }
    sort(B.begin(), B.end());
    vector<LL> Bsum(M + 1);
    for (int i = 1; i < M + 1; i++) {
        Bsum[i] = Bsum[i - 1] + B[i - 1];
    }
    LL ans = 0;
    for (int a : A) {
        int num = lower_bound(B.begin(), B.end(), P - a) - B.begin(); // 価格Bが適用される(Pが適用されない)数
        ans += (LL)a * num + Bsum[num] + (LL)P * (M - num);
    }
    cout << ans << endl;
    return 0;
}