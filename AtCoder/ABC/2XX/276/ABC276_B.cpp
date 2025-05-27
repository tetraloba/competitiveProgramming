//2023/01/08 11:04:03
//2023/01/08 11:13:16 AC.
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<set<int>> st(N);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        st[A - 1].insert(B - 1);
        st[B - 1].insert(A - 1);
    }
    for (int i = 0; i < N; i++) {
        int size = st[i].size();
        cout << size << ' ';
        for (int tmp : st[i]) {
            cout << tmp + 1 << ' ';
        }
        cout << endl;
    }
    return 0;
}