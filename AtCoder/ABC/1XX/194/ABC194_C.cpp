// 2025/01/06 10:32:19
// 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }

    sort(A.begin(), A.end());

    for (int i = 2; i < N; i++) {
        for (int j = 1; j < i; j++) {
            A[i] - A[j];
        }
    }
    cout <<  << endl;
    return 0;
}
/*
-5 -4 -3  8  9
 0  1  2 13 14 = 1 4 169 196
    0  1 12 13 = 1 144 169
       0 11 12 = 121 144
          0  1 = 1
 0  1  1 11  1
 0  1  5 

 1  2  4  8 16
 0  1  3  7 15
    0  2  6 14
       0  4 12
          0  8
             0
1^2 + 
(1 + 2)^2 + 2^2 + 
(1 + 2 + 4)^2 + (2 + 4)^2 + 4^2 + 
(1 + 2 + 4 + 8)^2 + (2 + 4 + 8)^2 + (4 + 8)^2 + 8^2

*/
/*
はえ～なるほどねえ。これは無理。(2025/01/06 10:52:10)
*/
