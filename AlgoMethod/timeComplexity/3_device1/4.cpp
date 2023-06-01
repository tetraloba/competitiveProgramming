//2022/08/14 11:39:44
//2022/08/14 11:49:46 TLE
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
    long long sum = 0;
    long long sum_same = 0;
    for (int i = 0; i < N; i++) {
        sum_same += A[i] * A[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            sum += A[i] * A[j];
        }
    }
    cout << sum * 2 + sum_same << endl;
    return 0;
}