//2022/08/30 16:24:11
//2022/08/30 16:50:52 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, Q;
    cin >> N;
    vector<int> A(N + 1), B(N + 1);
    for (int i = 1; i <= N; i++) {
        A[i] = B[i] = i;
    }
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int x;
        cin >> x;
        if (B[x] != N) {
            swap(A[B[x]], A[B[x] + 1]);
            B[A[B[x]]]--;
            B[x]++;
        } else {
            swap(A[B[x] - 1], A[B[x]]);
            B[A[B[x]]]++;
            B[x]--;
        }
        // cout << "A:";
        // for (int i = 1; i <= N; i++) {
        //     cout << A[i] << (i != N ? ' ' : '\n');
        // }
        // cout << "B:";
        // for (int i = 1; i <= N; i++) {
        //     cout << B[i] << (i != N ? ' ' : '\n');
        // }
    }
    for (int i = 1; i <= N; i++) {
        cout << A[i] << (i != N ? ' ' : '\n');
    }
    return 0;
}