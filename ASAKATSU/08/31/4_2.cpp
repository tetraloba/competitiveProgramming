//2022/08/31 07:39:27
//2022/08/31 08:15:47 WA
//2022/08/31 08:25:48 AC.
//ABC170_D - Not Divisible
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    map<int, int> mp;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        mp[A[i]]++;
    }
    // for (auto i: mp) { //debug
    //     cout << i.first << ':' << i.second << endl;
    // }
    if (mp[1]) { //1がある場合
        cout << (1 < mp[1] ? 0 : 1) << endl;
        return 0;
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        bool flag = true;
        for (int j = 2; j * j <= A[i]; j++) {
            if (!(A[i] % j)) {
                if (mp[j] || mp[A[i] / j]) {
                    flag = false;
                    break;
                }
            }
        }
        if (1 < mp[A[i]]) {
            flag = false;
        }
        if (flag) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
