//2022/08/15 07:30:07
//2022/08/15 07:34:24 AC.
//ABC248_B
#include <iostream>
#include <vector>
using namespace std;
int main(){
    long long int A, B, K;
    cin >> A >> B >> K;
    int i = 0;
    for (; A < B; i++) {
        A *= K;
    }
    cout << i << endl;
    return 0;
}