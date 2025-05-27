// 2024/02/17 15:52:08
// 2024/02/17 16:02:25 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    vector<int> sums(N);
    for (int i = 1; i < N; i++) {
        sums[i] = sums[i - 1] + (int)(S[i] == S[i - 1]);
    }
    int l, r;
    for (int i = 0; i < Q; i++) {
        cin >> l >> r;
        cout << sums[--r] - sums[--l] << endl;
    }
    return 0;
}