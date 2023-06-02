// 2023/06/02 22:44:34
// 2023/06/02 22:56:28 WA.
// 2023/06/02 23:05:05 WA.
// 2023/06/02 23:09:16 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());
    for (int i = 0; i < N; i++) {
        int l = i;
        int r = N - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (X < A[mid] - A[i]) {
                r = mid - 1;
            } else if (A[mid] - A[i] < X) {
                l = mid + 1;
            } else {
                cout << "Yes" << endl;
                return 0;
            }
        }  
    }
    for (int i = 0; i < N; i++) {
        int l = i;
        int r = N - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (X < A[i] - A[mid]) {
                l = mid + 1;
            } else if (A[i] - A[mid] < X) {
                r = mid - 1;
            } else {
                cout << "Yes" << endl;
                return 0;
            }
        }  
    }
    cout << "No" << endl;
    return 0;
}
// ソートして二分探索すればnlog(n)*2で行けそうだけど？
// あ、絶対差じゃないのか。大 - 小 とは限らないのか。逆verもう一回やっても間に合うかな？(笑)