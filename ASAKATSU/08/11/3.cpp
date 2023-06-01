//2022/08/11 07:59:04
//2022/08/11 08:11:08 WA
//2022/08/11 08:19:50 AC.
#include <iostream>
#include <climits>
using namespace std;
int pow(int a, int b){
    int ans = 1;
    for (int i = 0; i < b; i++) {
        ans *= a;
    }
    return ans;
}
int max(int a, int b){
    if (a < b) {
        return b;
    }
    return a;
}
int main(){
    int N, t[4];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> t[i];
    }
    int min = INT_MAX;
    int i_max = pow(2, N);
    for (int i = 0; i < i_max; i++) {
        int sum1 = 0, sum2 = 0;
        for (int j = 0; j < N; j++) {
            if (i % pow(2, j+ 1) / pow(2, j)) {
                sum1 += t[j];
            } else {
                sum2 += t[j];
            }
        }
        if (max(sum1, sum2) < min) {
            min = max(sum1, sum2);
        }
    }
    cout << min << '\n';
    return 0;
}
// C2の組み合わせ全探索してmax(sum1, sum2)の最小値