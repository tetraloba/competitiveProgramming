// 2024/03/30 21:00:01
// 
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }
    for (int a : A) {
        if (a % K == 0) {
            cout << a / K << ' ';
        }
    }
    cout << endl;
    return 0;
}