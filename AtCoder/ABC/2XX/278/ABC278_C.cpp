// 2023/06/20 00:24:01
// 2023/06/20 00:34:14 RE
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    int N, Q;
    cin >> N >> Q;
    vector<set<int>> vs(N);
    for (int i = 0; i < Q; i++) {
        int T, A, B;
        cin >> T >> A >> B;
        set<int>::iterator itr;
        switch (T) {
            case 1:
                vs[A - 1].insert(B - 1);
                break;
            case 2:
                itr = vs[A - 1].find(B - 1);
                if (itr != vs[A - 1].end()) {
                    vs[A - 1].erase(itr);
                }
                break;
            case 3:
                cout << (vs[A - 1].count(B - 1) && vs[B - 1].count(A - 1) ? "Yes" : "No") << endl;
                break;
        }
    }
    return 0;
}