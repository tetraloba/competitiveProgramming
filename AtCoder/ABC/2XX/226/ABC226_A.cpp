//2022/08/15 17:50:43
//2022/08/15 17:53:55 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    double X;
    cin >> X;
    int ans = (int)X + (5 <= (int)(X * 10) % 10 ? 1 : 0);
    cout << ans << endl;
    return 0;
}