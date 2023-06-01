//2022/08/14 02:31:39
//2022/08/14 02:32:59 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    string S, T;
    cin >> N >> S >> T;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] != T[i]) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}