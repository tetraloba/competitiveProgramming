//2022/08/13 21:00:10
//2022/08/13 21:01:16 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int L, R;
    cin >> L >> R;
    string S = "atcoder";
    for (int i = L - 1; i < R; i++) {
        cout << S[i];
    }
    cout << endl;
    return 0;
}