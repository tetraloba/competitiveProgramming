//2022/08/13 17:43:50
//2022/08/13 17:46:07 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int A, B;
    cin >> A >> B;
    if (B < A) {
        swap(A, B);
    }
    int gcm = 1;
    for (int i = 2; i <= A; i++) {
        if (!(A % i) && !(B % i)) {
            gcm = i;
        }
    }
    cout << gcm << endl;
    return 0;
}