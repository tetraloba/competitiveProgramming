// 2024/03/25 21:07:04
// 2024/03/25 21:11:19 AC
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }
    long long ans = (long long)(1 + K) * K / 2;
    sort(A.begin(), A.end());
    int tmp = 0;
    for (int a : A) {
        if (a == tmp) {
            continue;
        }
        if (K < a) {
            break;
        }
        tmp = a;
        ans -= a;
    }
    cout << ans << endl;
    return 0;
}
/*
先に足しておいて引いていく？いけるのかなあ・・・(2024/03/25 21:08:40)
*/
