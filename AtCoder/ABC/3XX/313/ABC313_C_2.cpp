// 2024/03/29 19:50:07
// 2024/03/29 19:57:11 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }

    sort(A.rbegin(), A.rend()); // 降順ソート    
    long long sum = 0;
    for (int a : A) {
        sum += a;
    }
    int ave = sum / N;
    int remain = sum - ave * N;
    // 左からremain個はave+1、それ以外はaveにする。
    long long ans2 = 0;
    int i = 0;
    while (i < remain) {
        ans2 += A[i] < (ave + 1) ? (ave + 1) - A[i] : A[i] - (ave + 1);
        i++;
    }
    while (i < N) {
        ans2 += A[i] < ave ? ave - A[i] : A[i] - ave;
        i++;
    }
    cout << ans2 / 2 << endl;
    return 0;
}
