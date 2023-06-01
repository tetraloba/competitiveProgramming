//2022/08/16 07:53:23
//2022/08/16 08:04:39 AC.
//ABC011_C - 123引き算
#include <iostream>
#include <vector>
using namespace std;
bool notNG(int N, int* NG){
    for (int i = 0; i < 3; i++) {
        if (N == NG[i]) {
            return false;
        }
    }
    return true;
}
int main(){
    int N, NG[3];
    cin >> N >> NG[0] >> NG[1] >> NG[2];
    if (notNG(N, NG)) {
        for (int i = 0; i < 100; i++) {
            if (0 <= N - 3 && notNG(N - 3, NG)) {
                N = N - 3;
            } else if (0 <= N - 2 && notNG(N - 2, NG)) {
                N = N - 2;
            } else if (0 <= N - 1 && notNG(N - 1, NG)) {
                N = N - 1;
            }
        }
    }
    cout << (N ? "NO" : "YES") << endl;
    return 0;
}