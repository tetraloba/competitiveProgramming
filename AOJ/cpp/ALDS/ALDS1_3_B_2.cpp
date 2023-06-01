//2022/08/21 15:13:33
//
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, q;
    cin >> n >> q;
    vector<pair<string, int>> process(n);
    for (int i = 0; i < n; i++) {
        cin >> process[i].first >> process[i].second;
    }
    int time = 0;
    bool flag = true;
    while (flag) {
        flag = false;
        for (auto itr = process.begin(); itr != process.end(); itr++) {
            time += min(q, itr->second);
            itr->second = max(itr->second - q, 0);
            if (!itr->second) {
                cout << itr->first << ' ' << time << endl;
                auto tmp = itr;
                itr--;
                process.erase(tmp); //itrでeraseするとitrの参照先が不正になるわけだが…
            }
            flag = true;
        }
    }
    return 0;
}