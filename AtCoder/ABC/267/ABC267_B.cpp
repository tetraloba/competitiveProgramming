//2022/10/06 09:24:49
//2022/10/06 09:43:48 AC. テキトウに書いたけど…
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int main(){
    pair<int, int> p[7] = {make_pair(0, 7), make_pair(0, 4), make_pair(2, 8), make_pair(1, 5), make_pair(3, 9), make_pair(0, 6), make_pair(0, 10)};
    string tmp;
    cin >> tmp;
    string S = "0" + tmp;
    if (S[1] == '0') {
        int i, j, k;
        for (i = 0; i < 7; i++) {
            if (S[p[i].first] == '1' || S[p[i].second] == '1') {
                break;
            }
        }
        for (j = 6; 0 <= j; j--) {
            if (S[p[j].first] == '1' || S[p[j].second] == '1') {
                break;
            }
        }
        // cout << "i=" << i << ", j=" << j << endl; //debug
        for (k = i + 1; k <= j - 1; k++) {
            if (S[p[k].first] == '0' && S[p[k].second] == '0') {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}