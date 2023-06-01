//2022/08/09 08:08:54
//2022/08/09 08:13:40 AC.
#include <iostream>
using namespace std;
int main(){
    int m, n, N;
    cin >> m >> n >> N;
    int sum = N;
    while (m <= N) {
        sum += (N / m) * n;
        N = N % m + (N / m) * n;
    }
    cout << sum << '\n';
    return 0;
}