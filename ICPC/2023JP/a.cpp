#include <bits/stdc++.h>
using namespace std;

int main(void) {
    while(1) {
        int n, indx;
        cin >> n;
        if (n == 0) {
            break;
        }
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a.at(i);
        }
        int near = 10000;
        for (int i = 0; i < n; i++) {
            if (abs(2023 - near) > abs(2023 - a.at(i))) {
                near = a.at(i);
                indx = i;
            }
        }
        if (near == 10000) {
            cout << 0 << endl;
        } else {
            cout << indx + 1 << endl;
        }
    }
    return 0;
}