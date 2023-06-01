//2022/08/19 20:32:44
//2022/08/19 20:36:16 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, Q;
    cin >> N;
    vector<int> A(N), sum(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (i) {
            sum[i] = sum[i - 1] + A[i];
        } else {
            sum[i] = A[i];
        }
    }
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        cout << sum[r - 1] - sum[l - 1] << endl;
    }
    return 0;
}