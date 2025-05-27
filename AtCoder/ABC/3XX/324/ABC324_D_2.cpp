// 2024/03/18 18:28:03
// 2024/03/18 19:20:01 AC.
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    int N;
    string S;
    cin >> N >> S;
    sort(S.rbegin(), S.rend());
    const int LIM = (int)pow(stoll(S), 0.5) + 1;
    long long ans = 0;
    int num1[10] = {0};
    for (char s : S) {
        num1[s - '0']++;
    }
    for (long long cand = 0; cand < LIM; cand++) {
        int num2[10] = {0};
        for (char t : to_string(cand * cand)) {
            num2[t - '0']++;
        }
        bool flag = true;
        for (int i = 1; i < 10; i++) {
            if (num1[i] != num2[i]) {
                flag = false;
            }
        }
        if (num1[0] < num2[0]) {
            flag = false;
        }
        ans += int(flag);
    }
    cout << ans << endl;
    return 0;
}
/*
next_permutation()するとO(13!)で間に合わないのか。
平方数が高々10^7しか無いので、それぞれSの並び替えで作れるかを判定すれば良いか。(2024/03/18 18:39:56)
*/
