//2022/08/20 13:26:17
//2022/08/20 13:29:35 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int Y;
    cin >> Y;
    bool ans = false;
    if (!(Y % 4)) {
        ans = true;
        if (!(Y % 100)) {
            ans = false;
            if (!(Y % 400)) {
                ans = true;
            }
        }
    }
    cout << (ans ? "YES" : "NO") << endl;
    return 0;
}