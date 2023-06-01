//2022/08/11 17:58:43
//2022/08/11 18:00:52 AC.
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
    int cnt = 0;
    for (int i = 1; i < N; i++) {
        if (A[i - 1] < A[i]) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}