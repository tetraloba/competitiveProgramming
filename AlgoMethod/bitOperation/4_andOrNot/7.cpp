//2022/08/18 19:07:57
//2022/08/18 19:13:54 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, S, Q, q1, qx;
    cin >> N >> S >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> q1 >> qx;
        if (q1) {
            cout << ((S & 1 << qx) ? "on" : "off") << endl;
        } else {
            S = S | 1 << qx;
        }
    }
    return 0;
}