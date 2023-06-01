#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "n:";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << i << ' ';
    }
    cout << '\b';
    cout << '#'; //空白検証用
    cout << '\n';
    return 0;
}