// 2024/04/16 22:52:12
// 
#include <iostream>
#include <vector>
using namespace std;
int main(){
    long long N;
    cin >> N;
    vector<int> prime(300000);
    for (int i = 0; i < prime.size(); i++) {
        prime[i] = i;
    }
    prime[1] = 0;
    int i = 0;
    auto itr = prime.begin();
    while (i < prime.size()) {
        if (prime[i]) {
            int j = i + prime[i];
            while (j < prime.size()) {
                prime[j] = 0;
                j += prime[i];
            }
        }
        i++;
    }
    // for (int i : prime) {
    //     cout << i << ' ';
    // }
    // cout << endl;
    vector<int> primes;
    for (int i : prime) {
        if (i) {
            primes.push_back(i);
        }
    }
    for (auto i : primes) {
        cout << i << ' ';
    }
    cout << endl;

    int i_a = 0, i_b = 1, i_c = primes.size() - 1;
    if ((long long)primes[i_a] * primes[i_a] * primes[i_b] * primes[i_c] * primes[i_c]) {
        ;
    }
    cout << (long long)299993 * 299993 * 12 << endl;
    // for (int i = 2; i < prime.size(); i++) {
    //     ;
    // }
    // int a = 2, b = 3, c = 5;
    // while (true) {
    //     ;
    // }
    // cout <<  << endl;
    return 0;
}
/*
10^12
1,000,000,000,000
100^2 * 100 * 100^2
500^5くらいで収まるか。
2024/04/16 23:02:59
いやまだまだいけるか
2^2 * 3 * 1000^2
10^11^0.5
10^6くらいか。なるほどギリギリってわけね。
2^2 * 3 * 999983^2 = 11,999,592,003,468
851891 => 8,708,619,310,572
810853 => 7,889,791,051,308
499957 => 2,999,484,022,188
299993 => 1,079,949,600,588
こんなものか。
*/
