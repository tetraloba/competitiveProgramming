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
        for (int i = 0; i < n; i++) {
            if (0 < process[i].second) {
                time += min(q, process[i].second);
                process[i].second = max(process[i].second - q, 0);
                if (!process[i].second) {
                    cout << process[i].first << ' ' << time << endl;
                }
                flag = true;
            }
        }
    }
    return 0;
}