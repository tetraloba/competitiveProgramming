//2022/08/05 07:34:49
//2022/08/05 07:37:55 AC.
#include <iostream>
using namespace std;
int main(){
    int N, K, a, sum = 0;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> a;
        sum += a;
        if (K <= sum) {
            cout << i + 1 << endl;
            break;
        }
    }
    return 0;
}