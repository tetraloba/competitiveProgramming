// 2023/05/14 13:49:19
// 2023/05/14 13:53:52 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<bool> v(N, true);
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if (v[i]) {
            v[num - 1] = false;
        }
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (v[i]) {
            cnt++;
        }
    }
    cout << cnt << endl;
    for (int i = 0; i < N; i++) {
        if (v[i]) {
            cout << i + 1 << ' ';
        }
    }
    cout << endl;
    return 0;
}