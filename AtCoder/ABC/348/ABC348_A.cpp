// 2024/04/06 21:00:07
// 2024/04/06 21:01:33 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        if (i % 3) {
            cout << 'o';
        } else {
            cout << 'x';
        }
    }
    cout << endl;
    return 0;
}
/*
剰余とif文書ければ解ける。
*/
