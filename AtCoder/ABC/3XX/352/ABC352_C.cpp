// 2024/06/25 19:10:00
// 2024/06/25 19:16:14 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    int head = 0;
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += A[i];
        if (head < B[i] - A[i]) {
            head = B[i] - A[i];
        }
    }
    ans += head;
    cout << ans << endl;
    return 0;
}
/*
肩は全員分加算されるから、最後に乗る人の頭が大きければ良い？(2024/06/25 19:13)
*/
