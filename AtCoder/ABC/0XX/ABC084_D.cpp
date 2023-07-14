// 2023/07/14 19:33:29
// 2023/07/14 20:08:46 AC.
#include <iostream>
#include <vector>
using namespace std;
bool islike2017(int n, vector<int>& primes){
    return primes[n] != 0 && primes[(n + 1) / 2] != 0;
}
void furui(vector<int>& primes){
    primes[1] = 0;
    for (int i = 2; i < primes.size(); i++) {
        if (primes[i] != 0) {
            for (int j = 2 * i; j < primes.size(); j += i) {
                primes[j] = 0;
            }
        }
    }
}
int main(){
    int Q;
    cin >> Q;
    vector<int> primes(100001);
    for (int i = 0; i < primes.size(); i++) {
        primes[i] = i;
    }
    furui(primes);
    // for (int i = 0; i < primes.size(); i++) {
    //     if (primes[i] != 0) {
    //         cout << primes[i] << ' ';
    //     }
    // }
    // cout << endl;
    vector<int> sum(100001);
    for (int i = 1; i <= sum.size(); i++) {
        if (islike2017(i, primes)) {
            sum[i] = sum[i - 1] + 1;
        } else {
            sum[i] = sum[i - 1];
        }
    }
    // for (int i = 0; i < 10; i++) {
    //     cout << i << ' ' << sum[i] << endl;
    // }
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        // cout << sum[r] << ' ' << sum[l - 1] << endl;
        cout << sum[r] - sum[l - 1] << endl;
    }
    return 0;
}