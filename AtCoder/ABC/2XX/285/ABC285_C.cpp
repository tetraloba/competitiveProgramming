// 2024/03/03 18:39:41
// 2024/03/03 18:44:30 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    string S;
    cin >> S;

    long long ans = 0;
    long long coef = 1;
    for (int i = S.size() - 1; 0 <= i; i--) {
        ans += coef * (S[i] - 'A' + 1);
        coef *= 26;
    }
    cout << ans << endl;
    return 0;
}
/*
普通に26進数。
解説を読んで。
ケツから26をかけて足していくのではなくて、頭から足して26をかけていくという手もあるのか。
勉強になった。
*/
