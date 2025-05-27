//2022/08/21 20:55:07
//2022/08/21 20:57:25 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    int tmp;
    cin >> tmp;
    int crt = tmp;
    for (int i = 0; i < N - 1; i++) {
        cin >> tmp;
        if (crt < tmp) {
            crt = tmp;
        } else {
            break;
        }
    }
    cout << crt << endl;
    return 0;
}