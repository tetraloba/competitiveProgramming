// 2023/07/12 20:52:03
// 2023/07/12 20:59:26 AC.
#include <iostream>
#include <vector>
#include <list>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    list<int> b;
    for (int i = 1; i <= n; i++) {
        if (i % 2) {
            b.push_back(a[i - 1]);
        } else {
            b.push_front(a[i - 1]);
        }
    }
    if (n % 2) {
        b.reverse();
    }
    for (int i : b) {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}