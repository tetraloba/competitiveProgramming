// 2023/06/11 09:36:31
// 2023/06/11 09:40:55 WA
// 2023/06/11 09:43:08 WA.
// 2023/06/11 09:43:53 WA
// 2023/06/11 09:44:35 WA
// 2023/06/11 09:46:55 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    const long long int  M = 998244353;
    long long int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    cout << ( ((((A % M) * (B % M)) % M) * (C % M)) % M + M - ((((D % M) * (E % M)) % M) * (F % M)) % M ) % M << endl;
    return 0;
}