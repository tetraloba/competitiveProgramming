//2022/08/14 11:20:40
//2022/08/14 11:34:34 WA
//2022/08/14 11:35:24 AC. long long
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    long long cnt = 0;
    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= N; y++) {
            if (0 < M - x - y) {
                cnt += min(M - x - y, N);
            } else {
                break;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}