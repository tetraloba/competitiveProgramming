//2022/10/31 18:41:55
//2022/10/31 18:46:10 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    int max_i = 0;
    for (int i = 1; i < N; i++) {
        if (v[max_i] < v[i]) {
            max_i = i;
        }
    }
    cout << max_i + 1 << endl;
    return 0;
}