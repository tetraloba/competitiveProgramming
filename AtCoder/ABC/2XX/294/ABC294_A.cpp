//2023/05/06 08:59:19
//2023/05/06 09:01:18 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        if (!(tmp % 2)) {
            cout << tmp << ' ';
        }
    }
    cout << endl;
    return 0;
}