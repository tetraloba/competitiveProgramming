//2022/08/15 13:50:35
//2022/08/15 13:52:56 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int L, R;
    cin >> L >> R;
    int cnt = 0;
    for (int i = L; i <= R; i++) {
        for (int j = i + 1; j <= R; j++) {
            if (i % 10 == j % 10) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}