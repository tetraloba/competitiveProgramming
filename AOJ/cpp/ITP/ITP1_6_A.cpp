#include <iostream>
using namespace std;
int main(){
    int n, a[1000];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = n - 1; 0 <= i; i--) {
        cout << a[i]/* << ' '*/;
        if (0 < i) {
            cout << ' ';
        } else {
            cout << '\n';
        }
    }
    // cout << "\b\n"; //バックスペースで余分な空白を削除するのは許されない模様。
    return 0;
}