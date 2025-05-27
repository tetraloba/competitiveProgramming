// 2024/11/30 11:22:30
// 2024/11/30 11:35:44 WA
// 2024/11/30 11:48:17 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N;
    long long M;
    cin >> N >> M;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }
    sort(A.begin(), A.end());
    int x = 0;
    for (int i = 0; i < N; i++) {
        if (M < (long long)(A[i] - x) * (N - i)) {
            x += M / (N - i);
            break;
        }
        M -= (long long)(A[i] - x) * (N - i);
        x = A[i];
    }
    if (x == A[N - 1]) {
        cout << "infinite" << endl;
    } else {
        cout << x << endl;
    }
    return 0;
}
/*
8
1 2 3 4
M,x = 4,1
M,x = 1,2
*/
