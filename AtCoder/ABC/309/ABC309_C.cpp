// 2023/11/10 20:56:41
// 2023/11/10 21:10:17 WA
#include <iostream>
#include <map>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    map<int, int> mp;
    mp[0] = 0;
    for (int i = 1; i <= N; i++) {
        int a, b;
        cin >> a >> b;
        mp[a] += b;
    }
    int num = 0;
    for (auto &e : mp) {
        num += e.second;
    }
    for (auto &e : mp) {
        num -= e.second;
        if (num <= K) {
            cout << e.first + 1 << endl;
            return 0;
        }
    }
}