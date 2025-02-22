// 2025/02/22 09:27:03
// 2025/02/22 09:30:40 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }
    
    long long ans = 0;
    for (int a : A) {
        int b = a * 2;
        ans += A.end() - lower_bound(A.begin(), A.end(), b);
    }
    cout << ans << endl;
    return 0;
}
/* 
ニブタンでNlogNだなあ。
 */
