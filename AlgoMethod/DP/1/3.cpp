//2022/08/12 13:57:34
//2022/08/12 14:00:56 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> v(N + 1);
    v[0] = 1;
    v[1] = 1;
    for (int i = 2; i <= N; i++) {
        v[i] = v[i - 2] + v[i - 1];
    }
    cout << v[N] << endl;
    return 0;
}