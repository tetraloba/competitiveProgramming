// 2024/02/21 12:18:59
// 2024/02/21 12:28:00 TLE
// 2024/02/21 12:32:07 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    long long T;
    cin >> N >> T;
    vector<int> A(N);
    for (int &a: A) {
        cin >> a;
    }
    long long sum_time = 0;
    for (int a : A) {
        sum_time += a;
    }
    T %= sum_time;
    int i = 0;
    while (A[i] < T) {
        T -= A[i++];
    }
    cout << i + 1 << ' ' << T << endl;
    return 0;
}
