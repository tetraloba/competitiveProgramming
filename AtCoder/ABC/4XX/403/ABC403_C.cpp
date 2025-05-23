// 2025/05/23 11:05:46
// 2025/05/23 11:12:34 AC.
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<set<int>> permissions(N); // ユーザiが見れるコンテストページの集合 Mは全てのコンテストページを表す
    for (int i = 0; i < Q; i++) {
        int q, x, y;
        cin >> q;
        switch (q) {
            case 1:
                cin >> x >> y;
                x--; y--;
                permissions[x].insert(y);
                break;
            case 2:
                cin >> x;
                x--;
                permissions[x].insert(M);
                break;
            case 3:
                cin >> x >> y;
                x--; y--;
                if (permissions[x].count(M) || permissions[x].count(y)) {
                    cout << "Yes" << endl;
                } else {
                    cout << "No" << endl;
                }
                break;
        }
    }
    return 0;
}
