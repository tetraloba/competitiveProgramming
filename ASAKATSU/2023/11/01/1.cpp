// 2023/11/01 07:30:06
// 2023/11/01 07:34:19 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> f;
    f.push_back(1);
    for (int i = 0; i < N; i++) {
        f.push_back((i + 1) * f[i]);
    }
    cout << f[N] << endl;
    return 0;
}