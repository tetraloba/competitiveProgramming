// 2023/11/28 01:32:32
// 2023/11/28 01:37:36 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }
    int tgt = 0;
    for (int i = 0; i < N; i++) {
        if (A[tgt] < i + 1) {
            tgt++;
        }
        cout << A[tgt] - (i + 1) << endl;
    }
    return 0;
}