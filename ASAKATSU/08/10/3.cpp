//2022/08/10 07:40:56
//2022/08/10 07:49:40 TLE
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int NA, NB, A[100000], B[100000];
    cin >> NA >> NB;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < NA; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < NB; i++) {
        cin >> B[i];
        for (int j = 0; j < NA; j++) {
            if (B[i] == A[j]) {
                // cout << A[j] << ':' << B[i] << endl;
                cnt1++;
                break;
            }
        }
    }
    // cout << cnt1 << ' ' << NA << ' ' << NB << endl;
    cout << fixed << (double)cnt1 / (NA + NB - cnt1) << endl;
    return 0;
}
//set使わないとTLEかな？