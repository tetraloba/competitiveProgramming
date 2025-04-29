// 2025/04/29 07:31:12
// 2025/04/29 07:35:01 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<long long> luca = {2, 1};
    for (int i = 0; i < N - 1; i++) {
        luca.push_back(luca.back() + *(++luca.rbegin()));
    }
    cout << luca[N] << endl;
    return 0;
}
