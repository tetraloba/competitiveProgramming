// 2024/05/11 19:50:47
// 2024/05/11 20:12:51 AC.
#include <iostream>
#include <vector>
using namespace std;
long long diff(long long a, long long b) {
    return a < b ? b - a : a - b;
}
int main(){
    long long N, A, B, P, Q, R, S;
    cin >> N >> A >> B >> P >> Q >> R >> S;
    for (long long i = P; i <= Q; i++) {
        for (long long j = R; j <= S; j++) {
            if (j - i == B - A) {
                cout << '#';
            } else if (i + j == A + B) {
                cout << '#';
            } else {
                cout << '.';
            }
        }
        cout << endl;
    }
    return 0;
}
