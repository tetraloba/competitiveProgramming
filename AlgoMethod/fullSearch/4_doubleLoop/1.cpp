//2022/08/14 02:46:03
//2022/08/14 02:51:05 AC.
#include <iostream>
#include <vector>
using namespace std;
bool isPrime(int n){
    bool flag = true;
    if (n == 1) {
        flag = false;
    } else if (n != 2) {
        for (int i = 2; i < n; i++) {
            if (!(n % i)) {
                flag = false;
                break;
            }
        }
    }
    return flag;
}
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (isPrime(A[i])) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}