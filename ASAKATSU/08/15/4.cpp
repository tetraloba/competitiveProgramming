//2022/08/15 08:06:44
//全く違う. 2022/08/15 08:22:18
//CODE FESTIVAL 2016 qual C B - K個のケーキ
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int K, T, a[100];
    cin >> K >> T;
    int max = 0;
    for (int i = 0; i < T; i++) {
        cin >> a[i];
        if (max < a[i]) {
            max = a[i];
        }
    }
    int d = 1;
    K -= max;
    while (0 < K - d) {
        max = max / 2 + (max % 2 ? 1 : 0);
        K -= d;
        d *= 2; //Kの最大が奇数だった場合に対応できていない。
    }
    cout << max - 1 << endl;
    return 0;
}