// 2025/03/03 14:04:24
// 2025/03/03 14:11:01 AC.
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }
    map<int, vector<int>> mp;
    for (int i = 0; i < N; i++) {
        mp[A[i]].push_back(i);
    }
    int ans = INT32_MAX;
    for (auto [k, v] : mp) {
        for (int i = 1; i < v.size(); i++) {
            ans = min(ans, v[i] - v[i - 1] + 1);
        }
    }
    cout << (ans == INT32_MAX ? -1 : ans) << endl;
    return 0;
}
