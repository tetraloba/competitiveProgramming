//2022/08/17 07:30:07
//2022/08/17 07:44:03 AC.
//ABC088_B - Card Game for Two
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    // for (int i = 0; i < N; i++) {
    //     cout << a[i] << ' ';
    // }
    // cout << endl;
    vector<int> sum(2);
    for (int i = 0; i < N; i++) {
        sum[i % 2] += a[i];
    }
    cout << sum[0] - sum[1] << endl;
    return 0;
}