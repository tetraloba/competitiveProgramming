//2022/08/14 11:15:05
//2022/08/14 11:20:22 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int min = 1000000001;
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] < min) {
            min = A[i];
        }
        sum += A[i];
    }
    cout << sum - min << endl;
    return 0;
}