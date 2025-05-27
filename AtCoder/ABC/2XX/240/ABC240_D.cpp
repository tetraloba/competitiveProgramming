// 2024/03/05 21:33:51
// 2024/03/05 21:48:52 WA
// 2024/03/05 21:52:58 AC.
#include <iostream>
#include <vector>
#define NUM 200000
using namespace std;
int main(){
    int N;
    cin >> N;
    int cnt = 0;
    vector<int> v(NUM), rep(NUM);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        cnt++;
        v[cnt] = a;
        if (a == v[cnt - 1]) {
            rep[cnt] = rep[cnt - 1] + 1;
        } else {
            rep[cnt] = 1;
        }
        if (v[cnt] == rep[cnt]) {
            cnt -= rep[cnt];
        }
        cout << cnt << endl;
        /* debug */
        // for (int i = 1; i <= cnt; i++) {
        //     cout << v[i] << ' ';
        // }
        // cout << endl;
    }
    return 0;
}
