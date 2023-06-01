//2022/08/13 17:30:38
//2022/08/13 17:31:40 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (!(N % i)) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}