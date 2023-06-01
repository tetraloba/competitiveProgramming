//2022/08/15 14:05:36
//2022/08/15 14:11:27 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, Q, k;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> Sum(N + 1);
    Sum[0] = 0;
    for (int i = 1; i <= N; i++) {
        Sum[i] = Sum[i - 1] + A[i - 1];
    }
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> k;
        cout <<  Sum[k] << endl;
    }
    return 0;
}