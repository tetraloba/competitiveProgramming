// 2023/06/25 21:57:27
// 2023/06/25 22:33:56 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, Q;
    string S, S1, S2;
    cin >> N;
    cin >> S;
    cin >> Q;
    S1 = S.substr(0, N);
    S2 = S.substr(N, N);
    bool swp = false;
    // cerr << S1 << ',' << S2 << endl;
    for (int i = 0; i < Q; i++) {
        int T, A, B;
        cin >> T >> A >> B;
        if (T == 1) {
            char *p1, *p2;
            if (N < A) {
                if (swp) {
                    p1 = &S1[A - N - 1];
                } else {
                    p1 = &S2[A - N - 1];
                }
            } else {
                if (swp) {
                    p1 = &S2[A - 1];
                } else {
                    p1 = &S1[A - 1];
                }
            }
            if (N < B) {
                if (swp) {
                    p2 = &S1[B - N - 1];
                } else {
                    p2 = &S2[B - N - 1];
                }
            } else {
                if (swp) {
                    p2 = &S2[B - 1];
                } else {
                    p2 = &S1[B - 1];
                }
            }
            // cerr << swp << '|' << *p1 << ':' << *p2 << endl;
            char tmp = *p1;
            *p1 = *p2;
            *p2 = tmp;
        } else {
            swp = !swp;
        }
        // if (swp) {
        //     cerr << S2 << ',' << S1 << endl;
        // } else {
        //     cerr << S1 << ',' << S2 << endl;
        // }
    }
    if (swp) {
        cout << S2 << S1 << endl;
    } else {
        cout << S1 << S2 << endl;
    }
    return 0;
}