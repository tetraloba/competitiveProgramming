//2022/08/21 09:47:26
//2022/08/21 10:16:39 RE
//2022/08/21 10:21:28 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, D;
    cin >> N >> D;
    vector<int> X(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }
    vector<int> sum(N - D + 1);
    int max_i = 0;
    for (int i = 0; i < N; i++) {
        if (i < D) {
            sum[0] += X[i];
            max_i = i;
            // cout << "i:" << i << " sum[0]:" << sum[0] << endl; //debug
        } else {
            sum[i - D + 1] = sum[i - D] + X[i] - X[i - D];
            if (sum[max_i - D + 1] <= sum[i - D + 1]) {
                max_i = i;
            }
            // cout << "i:" << i << " sum[i - D + 1]:" << sum[i - D + 1] << endl; //debug
        }
    }
    cout << max_i - D + 1 << '~' << max_i << endl;
    return 0;
}
//そういえばvectorのコンストラクタを未だよく理解していないな。X{0}みたいな書き方は何なんや？
//01234
//ooooo
//xxxoo
//sss