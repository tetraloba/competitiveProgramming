// 2023/11/02 23:19:55
// 2023/11/02 23:27:53 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    char p, q;
    cin >> p >> q;
    int arr[] = {3, 1, 4, 1, 5 ,9};
    if (q < p) {
        q = q ^ p;
        p = q ^ p;
        q = p ^ q;
    }
    int ans = 0;
    for (int i = p - 'A'; i < q - 'A'; i++) {
        ans += arr[i];
    }
    cout << ans << endl;
    return 0;
}