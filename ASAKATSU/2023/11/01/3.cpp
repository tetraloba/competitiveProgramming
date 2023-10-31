// 2023/11/01 07:38:14
// 2023/11/01 07:47:54 WA 5
// 2023/11/01 08:01:44 AC.
#include <iostream>
#include <vector>
using namespace std;
long long int nC2(int n){
    // if (n < 2) {
    //     return 0;
    // }
    return (long long int)n * (n - 1) / 2;
}
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> cnt(N);
    for (int i = 0; i < N; i++) {
        cnt[A[i] - 1]++;
    }
    long long int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += nC2(cnt[i]);
    }
    for (int i = 0; i < N; i++) {
        cout << sum - nC2(cnt[A[i] - 1]) + nC2(cnt[A[i] - 1] - 1) << endl;
    }
    return 0;
}