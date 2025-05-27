//2022/08/19 21:37:39
//2022/08/19 21:54:09 AC.
#include <iostream>
#include <vector>
#define NUM 1000000007
using namespace std;
int find(char c, string& T){
    for (int i = 0; i < T.size(); i++) {
        if (T[i] == c) {
            return i;
        }
    }
    return -1;
}
int main(){
    string S, T = "chokudai";
    cin >> S;
    long long cnt[8] = {0};
    for (int i = 0; i < S.size(); i++) {
        int index = find(S[i], T);
        if (index == -1) {
            continue;
        }
        if (index == 0) {
            cnt[index]++;
        } else {
            cnt[index] += cnt[index - 1];
        }
        if (NUM < cnt[index]) {
            cnt[index] %= NUM;
        }
    }
    cout << cnt[7] << endl;
    return 0;
}
// chokudai
// 00000000
// c1
// 10000000
// h1
// 11000000
// c1
// 21000000
// h2
// 23000000
// o3
// 23300000
// k3
// 23330000
// /ry
// 23333333!

// chokudaichokudaichokudai
// 00000000
// 10000000
// /ry
// 11111111
// 21111111
// 23111111
// 23411111
// 23451111
// /ry
// 23456789
// 33456789
// 36456789
// 3,6,10,5,6,7,8,9
// 3,6,10,15,6,7,8,9
// 3,6,10,15,21,7,8,9
// 3,6,10,15,21,28,8,9
// 3,6,10,15,21,28,36,9
// 3,6,10,15,21,28,36,45!