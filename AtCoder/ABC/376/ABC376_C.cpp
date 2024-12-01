// 2024/12/01 11:25:42
// 2024/12/01 11:36:29 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N), B(N - 1);
    for (int &a : A) {
        cin >> a;
    }
    for (int &b : B) {
        cin >> b;
    }
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    int x = -1;
    for (int i = 0, j = 0; i < N && j < N - 1; i++, j++) {
        if (B[j] < A[i]) {
            if (x == -1) {
                x = A[i];
                j--;
            } else {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    if (x == -1) {
        cout << A[N - 1] << endl;
    } else {
        cout << x << endl;
    }
    return 0;
}
/*
とりあえず順番は関係ないのでソートする。
1番大きいのを除いて全部入らないと駄目って認識でおｋ？(2024/12/01 11:29:13)
大きいのを入れた方が良いのか・・・(2024/12/01 11:30:26)
7 5 3 2
8 6 1
*/
