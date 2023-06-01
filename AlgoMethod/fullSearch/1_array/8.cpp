//2022/08/13 17:04:59
//2022/08/13 17:06:09 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int min = 101;
    for (int i = 0; i < N; i++) {
        if (A[i] < min) {
            min = A[i];
        }
    }
    cout << min << endl;
    return 0;
}