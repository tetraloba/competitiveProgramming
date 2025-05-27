// 2023/08/12 23:10:18
// 2023/08/12 23:14:52 WA
// 2023/08/12 23:23:03 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    string S;
    cin >> N >> S;
    int X = -1;
    int cnt = -1;
    for (char c : S) {
        if (c == 'o') {
            cnt = cnt == -1 ? 1 : cnt + 1;
        } else {
            X = X < cnt ? cnt : X;
            cnt = cnt == -1 ? -1 : 0;
        }
    }
    if (X == -1 && cnt != N) {
        X = cnt;
    }
    cout << X << endl;
    return 0;
}