// 2026/04/20 21:28:52
// 2026/04/20 09:34:51 21WA
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, K;
    long long X;
    cin >> N >> K >> X;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }
    sort(A.begin(), A.end());
    int ans = N - K; // 水のカップは全部飲む
    long long sum = 0;
    for (int i = 0; i < K; i++) {
        ans++;
        sum += A[i];
        if (X <= sum) {
            break;
        }
    }
    cout << (X <= sum ? ans : -1) << endl;
    return 0;
}
/*
2026/04/20 10:37:53
解説を読んで。
マジか・・・ASDだったかもしれん・・・
*/
