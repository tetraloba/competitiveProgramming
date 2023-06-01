//2022/08/18 21:19:49
//2022/08/18 21:23:30 AC.
#include <iostream>
using namespace std;
int main(){
    int N, S, Q;
    cin >> N >> S >> Q;
    for (int i = 0; i < Q; i++) {
        int q1, qx;
        cin >> q1 >> qx;
        if (q1) {
            cout << ((S & 1 << qx) ? "on" : "off") << endl;
        } else {
            S ^= 1 << qx;
        }
    }
    return 0;
}