// 2024/05/08 11:32:48
// 2024/05/08 11:49:29 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, Q;
    cin >> N;
    vector<pair<long long, int>> A(N);
    for (auto &a : A) {
        int tmp;
        cin >> tmp;
        a = {tmp, 0};
    }
    pair<int, int> all(0, -1);
    cin >> Q;
    for (int q = 1; q <= Q; q++) {
        int k, i, x;
        cin >> k;
        switch (k) {
            case 1:
                cin >> x;
                all = {x, q};
                break;
            case 2:
                cin >> i >> x;
                i--;
                if (A[i].second < all.second) {
                    A[i] = {all.first + x, q};
                    break;
                }
                A[i] = {A[i].first + x, q};
                break;
            case 3:
                cin >> i;
                i--;
                if (A[i].second < all.second) {
                    cout << all.first << endl;
                    break;
                }
                cout << A[i].first << endl;
                break;
        }
    }
    return 0;
}
/*
無駄なlong longは使わない。(2024/05/08 11:49:51)
*/
