// 2024/04/23 09:30:31
// 2024/04/23 09:45:45
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        long long a, s;
        cin >> a >> s;
        if (s < a * 2) {
            cout << "No" << endl;
            continue;
        }
        if ((s - a - a) & a) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
    return 0;
}
/*
sはaの2倍以上だよね。(2024/04/23 09:40:58)
s-a-a の結果がaと被らなければ良いのか？
つまりs-a-a & a == 0ってこと？(2024/04/23 09:42:40)
*/
/*
通って草
*/
