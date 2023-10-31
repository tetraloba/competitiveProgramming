// 2023/11/01 07:34:35
// 2023/11/01 07:38:03 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    string S = "DiscoPresentsDiscoveryChannelProgrammingContest2016";
    int W;
    cin >> W;
    int cnt = 0;
    for (int i = 0; i < S.length(); i++) {
        cout << S[i];
        cnt++;
        if (W <= cnt) {
            cout << endl;
            cnt = 0;
        }
    }
    if (cnt != 0) {
        cout << endl;
    }
    return 0;
}