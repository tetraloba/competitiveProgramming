// 2023/06/03 11:42:02
// 2023/06/03 12:04:38 WA.
// 2023/06/03 12:14:59 AC. シフト演算使えば良いのになあ(笑)
// 2023/06/03 12:25:20 AC. シフト演算でも 1LL << e みたいにキャストしなきゃいけないのか…
// 2023/06/03 12:34:54 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    long long int N;
    cin >> N;

    long long int tmp = N;
    vector<long long int> v;
    for (int i = 0; i < 60; i++) {
        if (tmp % 2) {
            v.push_back(1LL << i);
        }
        tmp = tmp >> 1;
    }

    // cout << "debug: ";
    // for (long long int i : v) {
    //     cout << i << ' ';
    // }
    // cout << endl;

    int combLimit = 1 << v.size();
    for (int i = 0; i < combLimit; i++) {
        long long int ans = 0;
        int j = i, cnt = 0;
        while (j) {
            if (j % 2) {
                ans += v[cnt];
            }
            j = j >> 1;
            cnt++;
        }
        cout << ans << endl;
    }
    return 0;
}
// N の 1 を 0 に書き換えていく順列？ いや2進数でできるか。