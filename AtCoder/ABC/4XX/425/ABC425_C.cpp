// 2025/12/12 21:14:33
// 2025/12/12 21:34:14 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (auto &a : A) {
        cin >> a;
    }

    /*累積和*/
    vector<long long> prefix(N + 1);
    for (int i = 1; i <= N; i++) {
        prefix[i] = prefix[i - 1] + A[i - 1];
    }
    
    // /* debug */
    // for (int p : prefix) {
    //     cerr << p << ' ';
    // }
    // cerr << endl;

    int head = 0;
    for (int i = 0; i < Q; i++) {
        int q, c, l, r, rl, rr;
        cin >> q;
        switch (q) {
            case 1:
                cin >> c;
                head = (head + c) % N;
                break;
            case 2:
                cin >> l >> r;
                rl = (head + l - 1) % N + 1;
                rr = (head + r - 1) % N + 1;
                // cerr << rl << ' ' << rr << endl; // debug
                if (rl <= rr) {
                    cout << prefix[rr] - prefix[rl - 1] << endl;
                } else {
                    cout << prefix[N] - (prefix[rl - 1] - prefix[rr]) << endl;
                }
                break;
        }
    }
    return 0;
}
/*
2025/12/12 21:15:23
先頭の位置を動かせばおｋってやつかな。
2025/12/12 21:18:01
累積和は流用できるっけ？
*/
