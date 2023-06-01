//2022/08/14 02:29:29
//2022/08/14 02:31:02 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    string S;
    cin >> S;
    int N = S.length();
    int cnt = 0;
    for (int i = 0; i < N - 1; i++) {
        if (S[i] == S[i + 1]) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}