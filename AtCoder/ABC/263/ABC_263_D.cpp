//2022/08/06 22:24:18
//2022/08/06 23:01:28 わけわかめ
#include <iostream>
using namespace std;
int main(){
    int N, L, R, A[200000];
    // int difX[200000], difY[200000];
    
    cin >> N >> L >> R;
    
    int difL = 0, maxL = 0, maxiL = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        /*difX[i] = */difL += A[i] - L;
        if (maxL < difL) {
            maxL = difL;
            maxiL = i;
        }
    }
    int difR = 0, maxR = 0, maxiR = N - 1;
    for (int i = N - 1; 0 <= i; i--) {
        /*difY[i] = */difR += A[i] - R;
        if (maxR < difR) {
            maxR = difR;
            maxiR = i;
        }
    }
    if (maxiL < maxiR) {
        if (maxL) {
            for (int i = 0; i <= maxiL; i++) {
                A[i] = L;
            }
        }
        if (maxR) {
            for (int i = N - 1; 0 <= i; i--) {
                A[i] = R;
            }
        }
    } else if (L < R) {
        for (int i = 0; i <= maxiL; i++) {
            A[i] = L;
        }
        for (int i = N - 1; maxiL < i; i--) {
            A[i] = R;
        }
    } else {
        for (int i = 0; i < maxiR; i++) {
            A[i] = L;
        }
        for (int i = N - 1; maxiR <= i; i--) {
            A[i] = R;
        }
    }
    cout << "A = ";
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cout << A[i] << ' ';
        sum += A[i];
    }
    cout << endl;
    cout << sum << endl;
    cout << "maxiL: " << maxiL << " maxiR: " << maxiR << endl;
    // for (int i = 0; i < N; i++) {
    //     cout << difX[i] << ' ';
    // }
    // cout << endl;
    //     for (int i = 0; i < N; i++) {
    //     cout << difY[i] << ' ';
    // }
    // cout << endl;

    return 0;
}