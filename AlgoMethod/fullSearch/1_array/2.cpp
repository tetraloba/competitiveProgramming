//2022/08/11 17:14:48
//2022/08/11 17:18:45 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, V;
    cin >> N >> V;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int cnt = 0;
    for (int i : A) {
        if (i == V) {
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}