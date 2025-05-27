// 2024/12/31 15:35:32
// 
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, S;
    cin >> N >> S;
    vector<int> A(N);
    for (int &a: A) {
        cin >> a;
    }

    long long F = 0;
    for (int a : A) {
        F += a;
    }
    S %= F;
    cerr << "S: " << S << endl;

    int l = -1, r = N;
    int D = S; // Diff
    bool end = false;
    while (l < N && 0 < D) {
        l++;
        D -= A[l];
    }
    cerr << "begin: (" << l << ' ' << r << ' ' << D << ")" << endl;
    // l:2 r:3 D:-3
    while (!end) {
        end = true;
        while (0 <= l && D < 0) {
            end = false;
            D += A[l];
            l--;
        }
        cerr << "after l: (" << l << ' ' << r << ' ' << D << ")" << endl;
        // l:1 r:3 D:1
        while (0 < r && 0 < D) {
            end = false;
            r--;
            D -= A[r];
        }
        cerr << "after r: (" << l << ' ' << r << ' ' << D << ")" << endl;
        // l:1 r:2 D:-3
        if (r <= l) {
            break;
        }
        if (D == 0) {
            break;
        }
    }
    cout << (D ? "No" : "Yes") << endl;
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
