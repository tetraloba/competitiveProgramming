//2022/08/20 07:48:39
//2022/08/20 07:52:12 WA
//2022/08/20 08:13:58 AC.
//ARC039_A - A - B problem
#include <iostream>
#include <vector>
using namespace std;
int pow(int a, int b){
    int ans = 1;
    for (int i = 0; i < b; i++) {
        ans *= a;
    }
    return ans;
}
int main(){
    int A, B;
    cin >> A >> B;
    for (int i = 2; 0 <= i; i--) {
        int N = pow(10, i);
        if (A / N % 10 != 9 || (i == 2 && B / N % 10 != 1) || (i < 2 && B / N % 10 != 0)) {
            if (9 - A / N % 10 < B / N % 10 - (i == 2 ? 1 : 0)) {
                B -= N * (B / N % 10 - (i == 2 ? 1 : 0));
            } else {
                // cout << A << ' ' << N * (9 - A / N % 10) << endl;
                A += N * (9 - A / N % 10);
            }
            break;
        }
    }
    // cout << A << ' ' << B << endl;
    cout << A - B << endl;
    return 0;
}