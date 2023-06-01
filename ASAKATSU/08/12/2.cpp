//2022/08/12 07:33:26
//2022/08/12 07:43:21 AC.
#include <iostream>
#include <set>
using namespace std;
int func(int N){
    int sum = 0;
    while (0 < N) {
        sum += N % 10;
        N /= 10;
    }
    return sum;
}
int main(){
    int N, A, B;
    cin >> N >> A >> B;
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        int tmp = func(i);
        // cout << tmp << endl;
        if (A <= tmp && tmp <= B) {
            sum += i;
        }
    }
    cout << sum << endl;
    return 0;
}