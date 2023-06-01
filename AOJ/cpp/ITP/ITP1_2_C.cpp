#include <iostream>
using namespace std;
int main(){
    int n1, n2, n3, tmp;
    cin >> n1 >> n2 >> n3;
    if (n2 < n1) {
        tmp = n1;
        n1 = n2;
        n2 = tmp;
    }
    if (n3 < n2) {
        tmp = n2;
        n2 = n3;
        n3 = tmp;
        if (n2 < n1) {
            tmp = n1;
            n1 = n2;
            n2 = tmp;
        }
    }
    cout << n1 << ' ' << n2 << ' ' << n3 << '\n';
    return 0;
}