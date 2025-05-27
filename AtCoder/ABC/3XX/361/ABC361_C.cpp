// 2024/07/19 22:42:47
// 2024/07/19 22:57:37 5WA
// 2024/07/19 22:59:11 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }
    
    sort(A.begin(), A.end());

    int ans = INT32_MAX;
    for (int i = 0; i < K + 1; i++) {
        ans = min(ans, A[i + N - K - 1] - A[i]);
    }
    cout << ans << endl;
    return 0;
}
/*
1 3 4 5 9
*/
