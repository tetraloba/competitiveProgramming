// 2024/04/21 17:34:49
// 2024/04/21 18:30:08 7WA
// 2024/04/21 18:38:47 AC.
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }

    long long sum = 0;
    map<int, int> mp;
    for (int a : A) {
        mp[a]++;
        sum += a;
    }

    long long rans = 0; // 机上に出せる総和の最大値
    long long t = 0; // ransの候補
    int expect = 0;
    for (auto [k, v] : mp) {
        if (k != expect) {
            t = 0;
        }
        t += (long long)k * v;
        if (rans < t) {
            rans = t;
        }
        expect = (k + 1) % M;
    }
    if (rans < sum) {
        for (auto [k, v] : mp) {
            if (k != expect) {
                break;
            }
            t += (long long)k * v;
            expect++;
        }
        if (rans < t) {
            rans = t;
        }
    }
    // cout << rans << endl; // debug
    cout << sum - rans << endl;
    return 0;
}
/*
グラフみたいな感じでまとめられるかしら？(2024/04/21 17:36:12)
X置けないと思っていたわ。(2024/04/21 18:21:59)
*/
