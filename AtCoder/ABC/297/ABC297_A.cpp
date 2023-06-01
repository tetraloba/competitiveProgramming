// 2023/06/01 19:36:25
// 2023/06/01 19:39:08 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, D;
    cin >> N >> D;
    int T;
    cin >> T;
    for (int i = 1; i < N; i++) {
        int tmp;
        cin >> tmp;
        if (tmp - T <= D) {
            cout << tmp << endl;
            return 0;
        }
        T = tmp;
    }
    cout << -1 << endl;
    return 0;
}