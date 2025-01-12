// 2025/01/12 21:17:01
// 2025/01/12 21:25:06 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for (int &a : A) {
        cin >> a;
    }
    int q;
    cin >> q;
    vector<int> possible(2000 + 1);
    possible[0] = true;
    for (int a : A) {
        for (int i = 2000; 0 <= i; i--) {
            if (possible[i]) {
                int p = i + a;
                if (2000 < p) {
                    continue;
                }
                possible[p] = true;
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int m;
        cin >> m;
        cout << (possible[m] ? "yes" : "no") << endl;
    }
    return 0;
}
