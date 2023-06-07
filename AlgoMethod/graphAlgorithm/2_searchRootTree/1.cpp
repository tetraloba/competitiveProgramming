// 2023/06/07 10:39:23
// 2023/06/07 10:50:27 AC.
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    for (int i = 1; i < N; i++) {
        cin >> A[i];
    }
    int tgt = X, cnt = 0;;
    while (tgt) {
        tgt = A[tgt];
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}