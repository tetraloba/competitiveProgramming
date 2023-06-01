//2022/08/19 09:03:54
//2022/08/19 09:07:58 WA オーバーフロー…
//2022/08/19 09:10:37 WA Kのオーバーフロー直すの忘れてたわｗｗ
//2022/08/19 09:21:57 AC.
//ABC261_C Big Array
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    int N;
    long long K;
    map<int, long long> mp;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        mp[a] += b;
    }
    for (auto i : mp) {
        if (K <= i.second) {
            cout << i.first << endl;
            return 0;
        } else {
            K -= i.second;
        }
    }
}
// 100,000 100,000
// 10,000,000,000