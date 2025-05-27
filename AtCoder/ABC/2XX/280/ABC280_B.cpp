//2023/01/06 19:13:18
//2023/01/06 19:18:59 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    vector<long long> A(N);
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        A[i] = S[i] - sum;
        sum += A[i];
    }
    for (int i = 0; i < N; i++) {
        cout << A[i] << ' ';
    }
    cout << endl;
    return 0;
}