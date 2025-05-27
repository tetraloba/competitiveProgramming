// 2024/03/23 19:22:54
// 2024/03/23 19:40:44 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, A, B;
    cin >> N >> A >> B;
    string S;
    cin >> S;
    S = S + S;
    // cout << S << endl; // debug
    long long ans = INT64_MAX;
    for (int A_num = 0; A_num < N; A_num++) {
        int l = A_num, r = N - 1 + A_num;
        int B_num = 0;
        for (int i = 0; i * 2 < N; i++) {
            if (S[l + i] != S[r - i]) {
                B_num++;
            }
        }
        long long cost = (long long)A * A_num + (long long)B * B_num;
        if (cost < ans) {
            ans = cost;
        }
    }
    cout << ans << endl;
    return 0;
}
/*
aab
Aでaba
Bでbab

abc
Bでcbc

aabb
Aでabba
操作の順番は関係ないな。(2024/03/23 19:27:47)

bcdfcgaa
fcgaabcd
最大 N/2 * B
Aは 0 ~ N-1 回 の N通り
N <= 5000なので全探索できるか。(2024/03/23 19:34:26)
*/
