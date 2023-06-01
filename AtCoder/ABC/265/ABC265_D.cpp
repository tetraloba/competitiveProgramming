//2022/08/21 21:37:45
//
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    long long P, Q, R;
    cin >> N >> P >> Q >> R;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int i, j;
    int sum;
    bool flag = false;
    for (i = 0; i < N - 3; i++) { //最後の要素とQR分を-3
        sum = 0;
        j = i;
        cout << '!';
        for (; j < N - 2; j++) {
            sum += A[j];
            if (P <= sum) {
                cout << "sum:" << sum << " P:" << P << endl; 
                break;
            }
        }
        if (sum == P) {
            flag = true;
            break;
        }
    }
    sum = 0;
    int k = j + 1;
    if (true) {
        cout << '#';
        flag = false;
        for (; k < N - 2; k++) {
            sum += A[k];
            if (Q <= sum) {
                break;
            }
        }
        if (sum == Q) {
            flag = true;
        }
    }
    sum = 0;
    int l = k + 1;
    if (true) {
        cout << '$';
        flag = false;
        for (; l < N - 1; l++) {
            sum += A[l];
            if (R <= sum) {
                break;
            }
        }
        if (sum == R) {
            flag = true;
        }
    }
    cout << i << ' ' << j << ' ' << k << ' ' << l << endl;
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}
// 数列の最後の数は使えない
// 連続する部分和？尺取法？