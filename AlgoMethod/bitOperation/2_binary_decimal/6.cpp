//2022/08/16 23:08:20
//2022/08/16 23:09:22 AC.
#include <iostream>
using namespace std;
int main(){
    int N;
    cin >> N;
    int ans = 1;
    for (int i = 0; i < N; i++) {
        ans *= 2;
    }
    cout << ans << endl;
    return 0;
}