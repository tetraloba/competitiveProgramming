// 2024/04/20 10:58:14
// 2024/04/20 11:06:22 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long diff(long long A, long long B){
    return A < B ? B - A : A - B;
}
int main(){
    int N, M;
    long long D;
    cin >> N >> M >> D;
    vector<long long> A(N), B(M);
    for (long long &a : A) {
        cin >> a;
    }
    for (long long &b : B) {
        cin >> b;
    }
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    auto itrA = A.begin(), itrB = B.begin();
    while (itrA != A.end() && itrB != B.end()) {
        if (diff(*itrA, *itrB) <= D) {
            cout << *itrA + *itrB << endl;
            return 0;
        }
        if (*itrA < *itrB) {
            itrB++;
        } else {
            itrA++;
        }
    }
    cout << -1 << endl;
    return 0;
}
