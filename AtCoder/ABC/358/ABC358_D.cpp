// 2024/06/29 15:29:01
// 2024/06/29 15:36:09 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    for (int &a : A) {
        cin >> a;
    }
    for (int &b : B) {
        cin >> b;
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    auto a_itr = A.begin();
    auto b_itr = B.begin();
    long long ans = 0;
    while (b_itr != B.end() && a_itr != A.end()) {
        if (*b_itr <= *a_itr) {
            ans += *a_itr;
            b_itr++;
        }
        a_itr++;
    }
    cout << (b_itr == B.end() ? ans : -1) << endl;
    return 0;
}
/*
買わなければならない箱の最低値を昇順に並べてずらしていけば良い？
*/
