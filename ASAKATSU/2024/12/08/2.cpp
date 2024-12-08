// ABC079_C - Train Ticket
// 2024/12/08 07:30:41
// 2024/12/08 07:36:28 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    char A, B, C, D;
    cin >> A >> B >> C >> D;
    vector<int> arr(3);
    arr[0] = B - '0';
    arr[1] = C - '0';
    arr[2] = D - '0';
    for (int c = 0; c < (1 << 3); c++) {
        int ans = A - '0';
        for (int i = 0; i < 3; i++) {
            if ((c >> i) & 1) {
                ans += arr[i];
            } else {
                ans -= arr[i];
            }
        }
        if (ans != 7) {
            continue;
        }
        cout << A;
        for (int i = 0; i < 3; i++) {
            if ((c >> i) & 1) {
                cout << '+';
            } else {
                cout << '-';
            }
            cout << arr[i];
        }
        cout << "=7" << endl;
        break;
    }
    return 0;
}
