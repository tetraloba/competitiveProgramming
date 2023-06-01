//2022/08/15 13:10:42
//2022/08/15 13:13:10 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int cnt = 0;
        for (int j = 1; j <= i; j++) {
            if (!(i % j)) {
                cnt++;
            }
        }
        if (cnt == K) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}