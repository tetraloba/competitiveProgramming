//2022/08/12 14:03:21
//2022/08/12 14:32:23 WA
//2022/08/12 15:18:58 AC.
//2022/08/12 15:50:53 AC.
#include <iostream>
using namespace std;
int func123(int N){
    if (!N) {
        return 1;
    }
    int sum = 0;
    if (1 <= N) {
        sum += func123(N - 1);
    }
    if (2 <= N) {
        sum += func123(N - 2);
    }
    if (3 <= N) {
        sum += func123(N - 3);
    }
    return sum;
}
int main(){
    int N;
    cin >> N;
    cout << func123(N) << endl;
    return 0;
}
// 再帰をふんだんに使って書いてみるか。
// 3 0 0 0
// 2 0 0 1
// 1 0 0 2
// 0 0 0 3 -> cbn(003) = 1
// 0 0 1 1 -> cbn(011) = 2
// 0 1 0 0 -> cbn(100) = 1