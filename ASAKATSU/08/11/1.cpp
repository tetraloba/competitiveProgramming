//2022/08/11 07:30:16
//2022/08/11 07:33:27 AC.
#include <iostream>
using namespace std;
int main(){
    int N;
    cin >> N;
    int sum = 0, m;
    for (int i = 0; i < N; i++) {
        cin >> m;
        sum += 80 - m >= 0 ? 80 - m : 0;
    }
    cout << sum << '\n';
    return 0;
}