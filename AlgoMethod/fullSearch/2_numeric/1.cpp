//2022/08/13 17:28:54
//2022/08/13 17:29:58 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (i % 2 && i % 3 && i % 5) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}