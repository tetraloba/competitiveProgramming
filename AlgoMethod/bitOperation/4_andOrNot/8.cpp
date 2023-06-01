//2022/08/18 19:16:13
//2022/08/18 19:23:34 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, S, Q;
    cin >> N >> S >> Q;
    for (int i = 0; i < Q; i++) {
        int q1, qx;
        cin >> q1 >> qx;
        switch (q1) {
          case 0 :
            S |= 1 << qx;
            break;
          case 1 :
            S &= ~(1 << qx);
            break;
          case 2 :
            cout << ((S & 1 << qx) ? "on" : "off") << endl;
            break;
        }
    }
    return 0;
}