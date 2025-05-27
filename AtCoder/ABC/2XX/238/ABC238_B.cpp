//2022/08/11 07:17:27
//2022/08/11 07:27:51 AC.
#include <iostream>
#include <set>
using namespace std;
int main(){
    int N, A, crt = 0;
    set<int> s;
    s.insert(0);
    s.insert(360);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A;
        crt = (crt + A) % 360;
        s.insert(crt);
    }
    int max = 0, tmp = 0;
    for (int i : s) {
        // cout << "i:" << i << " s:" << tmp << endl;
        if (max < i - tmp) {
            max = i - tmp;
        }
        tmp = i;
    }
    cout << max << '\n';
    return 0;
}