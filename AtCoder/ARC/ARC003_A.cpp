//2022/08/20 13:30:14
//2022/08/20 13:34:08 WA 精度不足 1e-9なのでsetprecisionが必要。
//2022/08/20 13:37:22 AC.
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int main(){
    int N;
    cin >> N;
    int cnt[5] = {0};
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        cnt[c - 'A']++;
    }
    cout << fixed << setprecision(10) << (double)(cnt[0] * 4 + cnt[1] * 3 + cnt[2] * 2 + cnt[3] * 1) / N << endl;
    return 0;
}