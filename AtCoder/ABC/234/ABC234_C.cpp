//2022/09/02 21:04:04
//
#include <iostream>
#include <vector>
using namespace std;
int main(){
    long long K;
    cin >> K;
    vector<bool> v;
    while (K) {
        v.push_back(K % 2);
        K /= 2;
    }
    auto itr = v.rbegin();
    while (true) {
        cout << (*itr ? 2 : 0);
        itr++;
        if (itr == v.rend()) {
            break;
        }
    }
    cout << endl;
    return 0;
}
// 2
// 20, 22
// 200, 202, 220, 222
// 2000, 2002, 2020, 2022, 2200, 2202, 2220, 2222