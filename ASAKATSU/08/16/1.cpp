//2022/08/16 07:30:05
//2022/08/16 07:33:26 AC.
//ABC123_A - Five Antennas
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int a[5], k;
    for (int i = 0; i < 5; i++) {
        cin >> a[i];
    }
    cin >> k;
    cout << (a[4] - a[0] <= k ? "Yay!" : ":(") << endl;
    return 0;
}