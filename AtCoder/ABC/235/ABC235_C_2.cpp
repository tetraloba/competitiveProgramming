// 2023/06/09 11:29:09
// 2023/06/09 11:37:32 AC. 大人しくmapを使いましたとさ。
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    int N, Q;
    cin >> N >> Q;
    map<int, vector<int>> A;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        A[tmp].push_back(i);
    }
    for (int i = 0; i < Q; i++) {
        int x, k;
        cin >> x >> k;
        if (A.find(x) != A.end()) {
            if (k <= A[x].size()) {
                cout << A[x][k - 1] + 1 << endl;
                continue;
            }
        }
        cout << -1 << endl;
    }
    return 0;
}