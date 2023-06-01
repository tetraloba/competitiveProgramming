//2022/08/13 17:02:54
//2022/08/13 17:04:36 AC.
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
    int cnt = 0, max = 0;
    for (int i = 0; i < N; i++) {
        if (max < A[i]) {
            max = A[i];
            cnt = i;
        }
    }
    cout << cnt << endl;
    return 0;
}