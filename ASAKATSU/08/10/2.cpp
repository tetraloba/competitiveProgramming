//2022/08/10 07:32:27
//2022/08/10 07:56:02 TLE
#include <iostream>
using namespace std;
int main(){
    int N, a[200000];
    cin >> N;
    int max = 0;
    long long int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        if (max < a[i]) {
            max = a[i];
        }
        sum = 0;
        int max_tmp = max;
        for (int j = 0; j <= i; j++) {
            sum += a[j] + max_tmp;
            if (max_tmp < a[j] + max_tmp) {
                max_tmp = a[j] + max_tmp;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
//最大で10^7 * 2 * 2^10^5
//差分をうまく使わないとなあ…
//どう考えてもA問題の難易度じゃないと思ったらARCか。
//やっぱり新しい値が増えた時に結果がどう変化するかを予め算出するのが正解だな。面倒くせえ。