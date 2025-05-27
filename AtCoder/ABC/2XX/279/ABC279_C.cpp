//2022/12/27 22:31:25
//2022/12/27 23:06:05 WA
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
    int H, W;
    cin >> H >> W;
    vector<long long> S(W, 0), T(W, 0);
    for (int i = 0; i < H; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < W; j++) {
            if (tmp[j] == '#') {
                S[j] += pow(2, i);
            }
        }
    }
    sort(S.begin(), S.end());
    for (int i = 0; i < H; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < W; j++) {
            if (tmp[j] == '#') {
                T[j] += pow(2, i);
            }
        }
    }
    sort(T.begin(), T.end());
    // for (int i = 0; i < W; i++) {
    //     cout << S[i] << ',' << T[i] << endl;
    // }
    cout << (S == T ? "Yes" : "No") << endl;
    // cout << (equal(S.cbegin(), S.cend(), T.cbegin()) ? "Yes" : "No") << endl;
    return 0;
}