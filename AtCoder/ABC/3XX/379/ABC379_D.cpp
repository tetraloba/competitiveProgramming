// 2024/11/26 12:08:34
// 2024/11/26 12:41:13 AC.
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    int Q;
    cin >> Q;
    map<long long, int> mp; // day, num あるdayに植えた植物のnum
    long long day = 0;
    for (int q = 0; q < Q; q++) {
        int n, v;
        cin >> n;
        switch (n) {
            case 1:
                mp[day]++;
                break;
            case 2:
                cin >> v;
                day += v;
                break;
            case 3:
                cin >> v;
                // cerr << day - v << "より前に植えた植物を収穫します" << endl; // debug
                long long ans = 0;
                auto itr = mp.begin();
                auto rm = itr;
                while (itr != mp.end()) {
                    if (v <= day - itr->first) {
                        rm = itr;
                        itr++;
                        ans += rm->second;
                        mp.erase(rm);
                    } else {
                        itr++;
                    }
                }
                cout << ans << endl;
        }
        /* debug */
        // for (auto [k, v] : mp) {
        //     cerr << k << ':' << v << ' ';
        // }
        // cerr << endl;
    }
    return 0;
}
/*
解説を読んで…
確かに、mapじゃなくてqueueで十分だったわ。
*/
