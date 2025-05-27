// 2024/11/28 18:33:14
// 2024/11/28 19:07:37 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> ul(M, M); // upper limit
    for (int i = 0; i < N; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        if (M <= l) {
            continue;
        }
        ul[l] = min(ul[l], r);
    }

    /* debug */
    // for (int r : ul) {
    //     cerr << r << ' ';
    // }
    // cerr << endl;

    /* 実際の上限を確定する */
    ul[M - 1] = min(ul[M - 1] - 1, M - 1);
    for (int i = M - 2; 0 <= i; i--) {
        ul[i] = min(ul[i] - 1, ul[i + 1]);
    }

    /* debug */
    // for (int r : ul) {
    //     cerr << r << ' ';
    // }
    // cerr << endl;

    /* 条件を満たす範囲を数え上げる */
    long long ans = 0;
    for (int l = 0; l < M; l++) {
        ans += ul[l] - l + 1;
    }
    cout << ans << endl;
    return 0;
}
/*
1 2 3 4
2   4 
1 3 3 4
1 2 1 1

1 2 3 4 5 6 7 8 9
1 2 3 4 5 5 5 5 5
- - - - - - - - -
0 0 0 0 0 0 0 0 0

 1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20
 6       11 19       12       13       20
 5 10 10 10 11 11 11 11 12 12 12 19 19 19 20 20 20 20 20 20
 5  9  8  7  7  6  5  4  4  3  2  8  7  6  6  5  4  3  2  1 = 102
*/
