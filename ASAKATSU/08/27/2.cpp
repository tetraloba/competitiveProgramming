//2022/08/27 07:35:31
//2022/08/27 07:42:20
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        // if (1 <= i) {
        //     sum += (A[i] - A[i - 1]) * (A[i] - A[i - 1]);
        // }
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            sum += (A[i] - A[j]) * (A[i] - A[j]);
        }
    }
    cout << sum << endl;
    return 0;
}
// 200 200 300000 12,000,000,000
// 300000 ^2 間に合わないか。
// TLE まあ知ってた。