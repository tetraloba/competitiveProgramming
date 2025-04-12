// 2025/04/12 21:03:22
// 2025/04/12 21:13:26 9WA
#include <iostream>
#include <vector>
using namespace std;
int main(){
    const int NUM = 1e9;
    int N, K;
    cin >> N >> K;
    vector<long long> A(max(K, N + 1));
    long long range = 0;
    for (int i = 0; i < K; i++) {
        A[i] = 1;
        range += A[i];
    }
    for (int i = K; i <= N; i++) {
        A[i] = range;
        range = (range + A[i] - A[i - K] + NUM) % NUM;
    }
    /* debug */
    // for (int i = 0; i <= N; i++) {
    //     cerr << A[i] << ' ';
    // }
    // cerr << endl;

    cout << A[N] << endl;
    return 0;
}
/*
4 2
1 1 2 3 5
*/
