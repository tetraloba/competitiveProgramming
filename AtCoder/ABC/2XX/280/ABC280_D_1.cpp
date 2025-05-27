// 2024/04/15 17:00:55
// 
#include <iostream>
#include <vector>
using namespace std;
int main(){
    long long K;
    cin >> K;
    int N = 1;
    long long Nbikkuri = 1;
    while (true) {
        N++;
        Nbikkuri *= N;
        if (Nbikkuri % K == 0) {
            cout << N << endl;
            return 0;
        }
    }
    return 0;
}
/*
素因数分解して一番大きい素数と、数出てくるやつを潰していく感じか。
*/
