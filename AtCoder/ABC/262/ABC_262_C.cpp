//2022/08/04 18:10:05
//2022/08/04 18:27:36 TLE
#include <iostream>
using namespace std;
int main(){
    int N, a[500000];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (a[i] == i + 1) { //a[i] < a[j]
            for (int j = 0; j < N; j++) {
                if (a[j] == j + 1 && i != j) {
                    // cout << i << ' ' << j << endl;
                    cnt++;
                }
            }
        } else if (a[a[i] - 1] == i + 1) { //a[j] < a[i]
            // cout << i << ' ' << a[i] - 1 << endl;
            cnt++;
        }
    }
    cout << cnt / 2 << '\n';
    return 0;
}