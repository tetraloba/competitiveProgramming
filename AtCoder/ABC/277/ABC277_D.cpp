// 2024/04/21 17:34:49
// 
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

    /* min_num, sum_key */
    int min_num = INT32_MAX;
    long long sum_key = 0;
    int expect = 0;
    for (auto [k, v] : mp) {
        if (k != expect) {
            min_num = 0;
        }
        if (v < min_num) {
            min_num = v;
        }
        sum_key += k;
        expect = k + 1;
        cout << k << ' ' << v << endl;
    }

    long long rans = 0;
    long long t = 0;
    expect = 0;
    for (auto [k, v] : mp) {
        if (v <= min_num || k != expect) {
            t = 0;
        }
        t += k;
        if (rans < t) {
            rans = t;
        }
        expect = k + 1;
    }
    if ((*mp.rbegin()).second == M - 1) {
        expect = 0;
        for (auto [k, v] : mp) {
            if (v <= min_num || k != expect) {
                t = 0;
                break;
            }
            t += k;
            expect++;
        }
        if (rans < t) {
            rans = t;
        }
    }
    cout << rans << endl;
    rans += sum_key * min_num;
    cout << rans << endl;

    cout << sum - rans << endl;
    return 0;
}
/*
グラフみたいな感じでまとめられるかしら？(2024/04/21 17:36:12)
X置けないと思っていたわ。(2024/04/21 18:21:59)
*/
