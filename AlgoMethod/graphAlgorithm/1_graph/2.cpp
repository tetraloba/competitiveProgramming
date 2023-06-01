//2022/09/06 10:24:28
//2022/09/06 10:33:13 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> v(N);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        v[A].push_back(B);
    }
    for (int i = 0; i < N; i++) {
        sort(v[i].begin(), v[i].end());
        int tmpN = v[i].size();
        for (int j = 0; j < tmpN; j++) {
            cout << v[i][j];
            if (j != tmpN - 1) {
                cout << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}