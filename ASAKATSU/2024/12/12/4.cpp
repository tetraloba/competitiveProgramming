// 2024/12/12 07:46:43
// 2024/12/12 08:04:32 WA
// 2024/12/12 08:08:33 31WA
// 2024/12/12 08:10:28 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }

    vector<int> HL(N), HR(N); // i項までの時に有り得る最大の高さ(片面ずつ)
    HL[0] = HR[N - 1] = 1;

    for (int i = 1; i < N; i++) {
        if (HL[i - 1] + 1 <= A[i]) {
            HL[i] = HL[i - 1] + 1;
        } else {
            HL[i] = min(HL[i - 1] + 1, A[i]);
        }
    }
    /* debug */
    // for (int hl : HL) {
    //     cerr << hl << ' ';
    // }
    // cerr << endl;

    for (int i = N - 2; 0 <= i; i--) {
        if (HR[i + 1] + 1 <= A[i]) {
            HR[i] = HR[i + 1] + 1;
        } else {
            HR[i] = min(HR[i + 1] + 1, A[i]);
        }
    }
    /* debug */
    // for (int hr : HR) {
    //     cerr << hr << ' ';
    // }
    // cerr << endl;

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, min(HL[i], HR[i]));
    }
    cout << ans << endl;
    return 0;
}
/*
片面ずつ考えて、小さい方でマージ(min())か。(2024/12/12 07:50:04)
0から初めて、高さは1しか増やせない、と。
DP的に、1項ずつ増やした時の最大値を求めていけば良さそう。(2024/12/12 07:51:05)
*/
