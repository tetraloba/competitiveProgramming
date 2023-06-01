//2022/08/25 07:37:38
//2022/08/25 08:02:23 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int Q;
    cin >> Q;
    vector<pair<int, int>> v;
    for (int i = 0; i < Q; i++) {
        int query, x, c;
        cin >> query;
        if (query == 1) {
            cin >> x >> c;
            v.push_back(make_pair(x, c));
        } else {
            cin >> c;
            long long sum = 0;
            while (c) {
                if (c < v.begin()->second) {
                    sum += (long long)c * v.begin()->first;
                    v.begin()->second -= c;
                    c = 0;
                } else {
                    sum += (long long)v.begin()->first * v.begin()->second;
                    c -= v.begin()->second;
                    v.erase(v.begin());
                }
            }
            cout << sum << endl;
        }
        // for (pair<int, int> i : v) {
        //     cout << i.first << ',' << i.second << ' ';
        // }
        // cout << endl;
    }
    return 0;
}
//右から出すと思ってた💩
//左ならリストの方がええか。