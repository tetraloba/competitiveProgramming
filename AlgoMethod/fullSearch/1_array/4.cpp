//2022/08/11 17:34:27
//2022/08/11 17:37:29 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, V;
    cin >> N >> V;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int max = -1;
    for (int i = 0; i < N; i++) {
        if (A[i] == V) {
            max = i;
        }
    }
    cout << max << endl;
    return 0;
}