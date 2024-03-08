// 2024/03/08 23:09:48
// 2024/03/08 23:15:59 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> P(N);
    for (int &p : P) {
        cin >> p;
    }
    
    for (int &p : P) {
        p = 100 - p;
    }

    next_permutation(P.begin(), P.end());

    for (int &p : P) {
        p = 100 - p;
    }

    for (int p : P) {
        cout << p << ' ';
    }
    cout << endl;
    return 0;
}
// 1 2 3
// 1 3 2
// 2 1 3
// 2 3 1
// 3 1 2
// 3 2 1

// 3 2 1
// 3 1 2
