#include <iostream>
using namespace std;
int main(){
    int x, i = 1;
    while (1) {
        cin >> x;
        if (x) {
            cout << "Case " << i << ": " << x << '\n';
        } else {
            break;
        }
        i++;
    }
    return 0;
}