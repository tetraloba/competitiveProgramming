//2022/08/28 07:30:03
//2022/08/28 07:31:34 AC.
//ABC077_A - Rotation
#include <iostream>
#include <vector>
using namespace std;
int main(){
    string S1, S2;
    cin >> S1 >> S2;
    if (S1[0] == S2[2] && S1[1] == S2[1] && S1[2] == S2[0]) {
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}