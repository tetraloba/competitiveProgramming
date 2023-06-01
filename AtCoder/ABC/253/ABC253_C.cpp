//2022/08/18 19:34:04
//2022/08/18 19:46:19 AC.
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    map<int, int> mp;
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int q;
        cin >> q;
        if (q == 1) {
            int x;
            cin >> x;
            mp[x]++;
        } else if (q == 2) {
            int x, c;
            cin >> x >> c;
            if (0 < mp[x] - c) {
                mp[x] -= c;
            } else {
                mp.erase(x);
            }
        } else {
            cout << mp.rbegin()->first - mp.begin()->first << endl;
        }
    }
    return 0;
}