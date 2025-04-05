// 2025/04/05 21:01:14
// 2025/04/05 21:05:22 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    long long X = 0;
    for (int i = 0; i <= M; i++) {
        long long t = 1;
        for (int j = 0; j < i; j++) {
            t *= N;
        }
        // cerr << "t: " <<  t << endl;
        X += t;
        if (1000000000 < X) {
            cout << "inf" << endl;
            return 0;
        }
    }
    cout << X << endl;
    return 0;
}
