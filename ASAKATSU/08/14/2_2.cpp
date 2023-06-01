//2022/08/14 07:31:13
//2022/08/14 08:01:50 TLE
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    vector<int> c(N);
    for (int i = 0; i < N; i++) {
        cin >> c[i];
    }
    int max = 0;
    for (int i = 0; i <= N - K; i++) {
        set<int> s;
        for (int j = i; j < i + K; j++) {
            s.insert(c[j]);
        }
        if (max < s.size()) {
            max = s.size();
        }
    }
    cout << max << endl;
    return 0;
}