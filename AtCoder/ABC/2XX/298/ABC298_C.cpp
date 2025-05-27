// 2023/11/03 12:42:20
// 2023/11/03 13:03:20 AC.
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
int main(){
    int N, Q;
    cin >> N >> Q;
    vector<map<int, int>> q2(N + 1);
    map<int, set<int>> q3;
    for (int k = 0; k < Q; k++) {
        int q, i, j;
        cin >> q;
        switch (q) {
            case 1:
                cin >> i >> j;
                q2[j][i] = (q2[j].count(i) ? q2[j][i] : 0) + 1;
                q3[i].insert(j);
                break;
            case 2:
                cin >> i;
                for (const auto& [key, value] : q2[i]) {
                    for (int l = 0; l < value; l++) {
                        cout << key << ' ';
                    }
                }
                cout << endl;
                break;
            case 3:
                cin >> i;
                for (int l : q3[i]) {
                    cout << l << ' ';
                }
                cout << endl;
                break;
        }
    }
    return 0;
}