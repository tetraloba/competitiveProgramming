//2022/08/10 07:30:10
//2022/08/10 07:32:15 AC.
#include <iostream>
using namespace std;
int main(){
    int N;
    string S, T;
    cin >> N >> S >> T;
    for (int i = 0; i < N; i++) {
        cout << S[i] << T[i];
    }
    cout << endl;
    return 0;
}