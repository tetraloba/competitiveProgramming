// 2023/06/28 00:59:25
// 2023/06/28 01:04:50 AC.
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
    for (int i : A) {
        sum += i;
    }
    cout << sum * sum << endl;
    return 0;
}