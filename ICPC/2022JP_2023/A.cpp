// 2023/07/05 20:20:38
// 2023/07/05 20:30:43 AC?
#include <iostream>
#include <vector>
using namespace std;
int solve(int n){
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int cnt = 0;
    for (int i = 1; i < n - 1; i++) {
        if (v[i - 1] < v[i] && v[i] > v[i + 1]) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
int main(){
    while (true) {
        int n;
        cin >> n;
        if (!n) {
            break;
        }
        solve(n);
    }
}