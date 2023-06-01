//2022/08/13 07:31:17
//2022/08/13 07:44:04 WA
//2022/08/13 07:46:39 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, M, L = 1, R = 100000;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int tmpL, tmpR;
        cin >> tmpL >> tmpR;
        if (L < tmpL) {
            L = tmpL;
        }
        if (tmpR < R) {
            R = tmpR;
        }
    }
    cout << (0 < R - L + 1 ? R - L + 1 : 0) << endl;
    return 0;
}