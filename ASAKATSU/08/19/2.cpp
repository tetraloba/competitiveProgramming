//2022/08/19 07:42:00
//2022/08/19 07:44:43 AC.
//ABC028_B - 文字数カウント
#include <iostream>
#include <vector>
using namespace std;
int main(){
    string S;
    cin >> S;
    int cnt[6] = {0};
    for (int i = 0; i < S.size(); i++) {
        cnt[S[i] - 'A']++;
    }
    for (int i = 0; i < 6; i++) {
        cout << cnt[i] << (i != 5 ? ' ' : '\n');
    }
    return 0;
}