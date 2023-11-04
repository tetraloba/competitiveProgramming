// 2023/11/04 20:21:32
// 2023/11/04 20:23:15 WA Overflowか
// 2023/11/04 20:24:57 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    long long int N;
    cin >> N;
    while (N % 2 == 0) {
        N /= 2;
    }
    while (N % 3 == 0) {
        N /= 3;
    }
    cout << (N == 1 ? "Yes" : "No") << endl;
    return 0;
}