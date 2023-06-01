//2022/08/11 17:30:40
//2022/08/11 17:32:41 AC.
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
    for (int i : A) {
        if (0 < i) {
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}