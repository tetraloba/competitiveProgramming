// 2023/06/28 01:05:43
// 2023/06/28 01:08:32 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    long long sum = 0;
    long long ans = 0;
    for (int i : A) {
        ans += sum * i;
        sum += i;
    }
    cout << ans << endl;
    return 0;
}
// 想定解は前問との差分で求めているけど、累積和的な考えを使っても解けるよね。こちらの方が余計に値が大きくならないから良さそう。