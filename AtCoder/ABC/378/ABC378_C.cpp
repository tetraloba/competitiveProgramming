// 2024/12/03 13:17:20
// 2024/12/03 13:29:06 AC.
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }
    map<int, int> la;
    for (int i = 0; i < N; i++) {
        if (la.count(A[i])) {
            cout << la[A[i]] << ' ';
        } else {
            cout << -1 << ' ';
        }
        la[A[i]] = i + 1;
    }
    cout << endl;
    return 0;
}
