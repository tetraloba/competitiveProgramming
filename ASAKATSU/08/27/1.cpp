//2022/08/27 07:30:06
//2022/08/27 07:35:19 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, K, M, A;
    cin >> N >> K >> M;
    int sum = 0;
    for (int i = 0; i < N - 1; i++) {
        cin >> A;
        sum += A;
    }
    int ans = N * M - sum;
    cout << (K < ans ? -1 : max(0, ans)) << endl;
    return 0;
}