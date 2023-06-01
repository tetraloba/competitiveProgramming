//2022/08/19 20:37:30
//2022/08/19 20:45:47 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, Q;
    cin >> N;
    vector<int> sum(N);
    sum[0] = 0;
    for (int i = 1; i < N; i++) {
        int d;
        cin >> d;
        sum[i] = sum[i - 1] + d;
    }
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        cout << sum[r] - sum[l] << endl;
    }
    return 0;
}