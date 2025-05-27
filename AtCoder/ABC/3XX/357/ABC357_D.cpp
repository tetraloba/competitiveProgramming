// 2024/07/13 11:21:05
// 2024/07/13 12:21:06 むり
#include <iostream>
#include <vector>
#define NUM 998244353
using namespace std;
int main(){
    long long N;
    cin >> N;
    long long L = 1;
    long long tmp = N;
    while (tmp) {
        L *= 10;
        tmp /= 10;
    }

    long long n = N % NUM;
    long long l = L % NUM;
    vector<int> cache(NUM, -1);
    cache[n] = 0;
    for (long long cnt = 1; cnt < N; cnt++) {
        n = (n * l % NUM + N % NUM) % NUM;
        if (cache[n] != -1) {
            cout << "cached!! " << n << ' ' << cache[n] << ' ' << cnt << endl;
            return 0;
        }
        cache[n] = cnt;
    }
    cout << "end..." << endl;
    cout << n << endl;
    return 0;
}
/*
((N * len + N) * len + N)...
先にN %= NUMしても答え変わらないんだっけ？
*/
