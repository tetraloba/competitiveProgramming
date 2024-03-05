// 2024/03/05 20:59:14
// 2024/03/05 21:25:28 AC.
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool isPrime(int n){
    if (n == 2) {
        return true;
    }
    int lim = pow(n, 0.5);
    for (int i = 2; i <= lim; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
int main(){
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    int cnt = 0; // 素数でない整数の連続回数
    for (int i = A + C; i <= B + D; i++) {
        cnt = isPrime(i) ? 0 : cnt + 1;
        if (D - C + 1 <= cnt) {
            cout << "Takahashi" << endl;
            return 0;
        }
    }
    cout << "Aoki" << endl;
    return 0;
}
/*
A <= t <= B を満たすtについて、t+C <= a <= t+D の範囲に素数が存在しないtが存在するなら高橋くんの勝ち。
(2024/03/05 21:03:14)
A+C ~ B+Dの範囲で、素数の現れないD-C+1 以上の長さの連続区間が有れば良い？(2024/03/05 21:10:38)
51 160
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47
53 59 61 67 71 73 79 83 89 97 101 103 107 109 113 127 131 137 139 149 151 157
163 167 173 179 181 191 193 197 199 
*/
