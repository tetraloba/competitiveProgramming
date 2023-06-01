//2022/08/13 22:09:06
//2022/08/13 22:18:58 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    string S;
    cin >> S;
    string T = "atcoder";
    int cnt = 0;
    for (int i = 0; i < 7; i++) {
        int j = i;
        while (S[j] != T[i]) {
            j++;
        }
        // cout << T[i] << 'j' << j << endl;
        for (int k = 0; k < j - i; k++) {
            swap(S[j - k], S[j - k - 1]);
            cnt++;
        }
        // cout << T[i] << cnt << endl;
    }
    cout << cnt << endl;
    return 0;
}
// catredo
// actredo
// atcredo
// atcreod
// atcroed
// atcored
// atcorde
// atcodre
// atcoder