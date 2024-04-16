// 2024/04/16 23:22:47
// 2024/04/16 23:33:37 11WA
// 2024/04/16 23:36:49 4WA
// 2024/04/16 23:49:29 1WA
// 2024/04/16 23:50:59 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    long long A, M, L, R;
    cin >> A >> M >> L >> R;
    long long L_tree, R_tree;
    if (A < L) {
        L_tree = A + ((L - 1 - A) / M + 1) * M;
    } else {
        L_tree = A - (A - L) / M * M;
    }
    if (A <= R) {
        R_tree = A + (R - A) / M * M;
    } else {
        R_tree = A - ((A - R - 1) / M + 1) * M;
    }
    cout << (R_tree - L_tree) / M + 1 << endl; // R_tree < L_tree だと0になる
    return 0;
}
/*
Lの直後にあるクリスマスツリーとRの直前にあるクリスマスツリーを求めるのが楽？(2024/04/16 23:24:58)
2 7 12 17 22
A < L のとき
A + (L - A) / M * M
L < A のとき
A - (A - L) / M * M
A < R のとき
*/
