//2022/08/30 15:49:38
//2022/08/30 15:55:15 WA
//2022/08/30 15:58:52 AC.
#include <iostream>
#include <vector>
#define NUM 998244353
using namespace std;
int main(){
    long long N;
    cin >> N;
    if (N < 0) {
        N *= -1;
        cout << (N % NUM ? NUM - N % NUM : 0) << endl;
        return 0;
    }
    cout << N % NUM << endl;
    return 0;
}
// -26 9
// -27 9 -> 0