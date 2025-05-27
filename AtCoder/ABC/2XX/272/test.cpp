// 2023/06/16 00:40:14
// 2023/06/16 02:14:51 WA
// 2023/06/16 02:25:01 TLE.
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
int main(){
    int N = 400;
    map<int, int> mp;
    for (int i = 0; i < N; i++) {
        mp[i * i] = i;
    }

    int M;
    for (M = 0; M <= 100; M++) {
        vector<pair<int, int>> mv;
        // for (int i = 0; i < M; i++) {
            for (auto kv : mp) {
                if (mp.find(M - kv.first) != mp.end()) {
                    mv.push_back(make_pair(kv.second, mp[M - kv.first]));
                    // cout << "kv.f(" << kv.first << ")" << endl;
                }
            }
        // }
        cout << '[' << M << ':' << mv.size() << ']' << endl;
        for (int i = 0; i < mv.size(); i++) {
            cout << mv[i].first << ':' << mv[i].second << endl;
        }
    }
    // cerr << "mv is " << mv.first << ':' << mv.second << endl; // debug

    return 0;
}
