// 2024/12/31 15:35:32
// 2024/12/31 17:00:15 RE
// 2024/12/31 17:14:02 WA
// 2024/12/31 17:22:15 TLE
// 2024/12/31 17:25:52 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    long long S;
    cin >> N >> S;
    vector<int> A(2 * N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    long long F = 0;
    for (int i = 0; i < N; i++) {
        F += A[i];
    }
    S %= F;
    // cerr << "S: " << S << endl; // debug

    for (int i = N; i < 2 * N; i++) {
        A[i] = A[i - N];
    }

    int l = 0, r = -1;
    long long sum = 0; // sum from A[l] to A[r]
    bool end = false;
    // cerr << "begin: (" << l << ' ' << r << ' ' << sum << ")" << endl; // debug
    while (!end) {
        end = true;
        while (l <= r && S < sum) {
            end = false;
            sum -= A[l];
            l++;
        }
        // cerr << "after l: (" << l << ' ' << r << ' ' << sum << ")" << endl; // debug
        while (r < 2 * N - 1 && sum < S) {
            end = false;
            r++;
            sum += A[r];
        }
        // cerr << "after r: (" << l << ' ' << r << ' ' << sum << ")" << endl; // debug
        if (sum == S) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
/*
A1~ANの和で剰余を取って、後は前後から挟む感じか。(2024/12/31 15:38:17)
特殊な尺取法的な。分かるんだけど書けない。(2024/12/31 15:39:34)
とりあえずA1からSを超えるまで総和を取って、多いなら減らして、少ないならANから足していく感じか。(2024/12/31 15:40:38)
境界ヤバそう…(2024/12/31 15:40:49)
  0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19
748 169 586 329 972 529 432 519 408 587 138 249 656 114 632 299 984 755 404 772

20 39
7 1 5 3 9 5 3 5l38 4 5 1 2 6 1 6 2 9 7 4 45r7

こういう取り方があり得るのか。
1 2 3 4 5 1 || 2 3 4 5 1 |2 3| 4 5 1 2 3 || 4 5 
累積和取って尺取法せねばならんということかな。
倍の数列2Nを対象にすればよいか。(2024/12/31 16:50:35)

*/
