//2022/08/24 07:33:29
//2022/08/24 07:37:47 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    N = 2025 - N;
    for (int i = 1; i <= N && i <= 9; i++) {
        if (N % i == 0) {
            if (1 <= N / i && N / i <= 9) {
                cout << i << " x " << N / i << endl;
            }
        }
    }
    return 0;
}