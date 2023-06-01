//2022/08/18 07:40:09
//2022/08/18 07:55:08 あかんわ。重複したら無理。
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    int N;
    string S;
    cin >> N >> S;
    map<string,int> mp;
    for (int i = 0; i < N - 1; i++) {
        char tmp[3];
        tmp[0] = S[i];
        tmp[1] = S[i + 1];
        tmp[2] = 0;
        mp[tmp]++;
    }
    int max1 = 0, max2 = 0;
    for (auto i : mp) {
        cout << i.first << ' ' << i.second << endl;
        if (max1 <= i.second || max2 <= i.second) {
            if (max1 < max2) {
                max1 = i.second;
            } else {
                max2 = i.second;
            }
        }
    }
    cout << N - max1 - max2 << endl;
    return 0;
}