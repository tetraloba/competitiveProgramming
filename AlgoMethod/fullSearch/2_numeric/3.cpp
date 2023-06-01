//2022/08/13 17:32:49
//2022/08/13 17:39:28 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    bool flag = true;
    if (N == 1) {
        flag = false;
    }
    for (int i = 2; i < N; i++) {
        if (!(N % i)) {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}