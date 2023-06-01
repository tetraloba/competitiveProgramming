//2022/08/22 07:37:10
//2022/08/22 07:44:11 WA
//2022/08/22 07:57:03 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int a, b, n;
    cin >> a >> b >> n;
    if (b < a) {
        swap(a, b);
    }
    int i;
    for (i = n; i < n + b; i++) {
        if (!(i % b)) {
            break;
        }
    }
    for (; i <= 30000; i += b) {
        if (!(i % a)) {
            cout << i << endl;
            return 0;
        }
    }
}
//真面目に素因数分解して最小公倍数求める必要はなし？