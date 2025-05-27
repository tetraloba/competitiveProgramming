// 2024/02/29 21:54:23
// 2024/02/29 22:09:28 WA
// 2024/02/29 22:40:31 RE
// 2024/02/29 22:56:33 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    for (int &a : A) {
        cin >> a;
    }
    for (int &b : B) {
        cin >> b;
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int ans = 0; // 価格
    int seller = 0, buyer = M; // 売り手と買い手の数
    while (seller < buyer) {
        if (A[seller] <= B[M - buyer]) {
            ans = A[seller];
            while (seller < N && A[seller] == ans) {
                seller++;
            }
            if (seller == N) {
                break;
            }
        } else if (B[M - buyer] < A[seller]) {
            ans = B[M - buyer] + 1;
            while (0 < buyer && B[M - buyer] == ans - 1) {
                buyer--;
            }
        }
    }
    while (0 < buyer && seller < buyer) {
        ans = B[M - buyer] + 1;
        buyer--;
    }
    cout << ans << endl;
    return 0;
}
// 90 110 120
// 80 100 120 10000
// O(N log N)で良いなら全部試して二分探索していけば良さげ。 (2024/02/29 22:00:15)
// 無理だった。
