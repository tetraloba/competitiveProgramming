// 2024/02/24 19:20:21
// 2024/02/24 19:41:37 AC.
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> B(A);
    sort(B.rbegin(), B.rend());
    map<int, long long> mp;
    long long sum = 0;
    for (int b : B) {
        if (!mp.count(b)) {
            mp[b] = sum;
        }
        sum += b;
    }
    for (int a : A) {
        cout << mp[a] << ' ';
    }
    cout << endl;

    return 0;
}