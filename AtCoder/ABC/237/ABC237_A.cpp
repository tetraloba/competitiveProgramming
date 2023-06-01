//2022/08/15 19:51:11
//2022/08/15 19:57:02 AC.
#include <iostream>
#include <vector>
using namespace std;
long long int pow(int a, int b){
    long long int ans = 1;
    for (int i = 0; i < b; i++) {
        ans *= a;
    }
    return ans;
}
int main(){
    long long int N;
    cin >> N;
    long long int A = pow(2, 31);
    cout << (-A <= N && N < A ? "Yes" : "No") << endl;
    return 0;
}