// 2026/04/02 21:47:41
// 2026/04/02 21:52:26 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }
    int right = A[0];
    int ans = 1;
    for (int i = 1; i < N; i++) {
        if (right <= i) {
            break;
        }
        right = max(right, i + A[i]);
        ans++;
    }
    cout << ans << endl;
    return 0;
}
