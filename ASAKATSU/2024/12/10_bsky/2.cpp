// 2024/12/10 08:07:02
// 2024/12/10 08:21:01 WA
// 2024/12/10 08:38:28 1WA
// 2024/12/10 09:00:29 AC.
// ABC185_C - Duodecim Ferra
#include <iostream>
#include <vector>
using namespace std;

const int N = 12;
const vector<int> prime_factorized_N_factorial = {11, 7, 5, 5, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2}; // (N - 1)の階乗を素因数分解したもの

int solve(int L){
    vector<int> arr(N - 1);
    for (int i = 0; i < N - 1; i++) {
        arr[i] = L - 1 - i;
    }

    for (int d : prime_factorized_N_factorial) {
        for (int &a : arr) {
            if (a % d == 0) {
                a /= d;
                break;
            }
        }
    }

    long long ans = 1;
    for (int a : arr) {
        ans *= a;
    }
    cout << ans << endl;
    return 0;
}

int main(){
    int L;
    cin >> L;
    solve(L);

    // for (int i = 12; i <= 200; i++) {
    //     cerr << "i: " << i << endl;
    //     solve(i);
    // }

    // solve(36);

    return 0;
}
/*
(L - 1) C 11 でしょ (2024/12/10 08:08:43)
以下にオーバーフローさせずに計算するかってこと？Pythonゲーでは(2024/12/10 08:11:26)

うーん、11!側で割っても、11!側から剰余取っても、WAが出るなあ。L=36とかが厳しい。
先に11!を素因数分解してしまうのが楽か…(2024/12/10 08:49:51)
*/
/*
解説は異なる3つの解法を提示している。
*/
