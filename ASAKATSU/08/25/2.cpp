//2022/08/25 07:31:33
//2022/08/25 07:37:29 WA
//2022/08/25 07:39:48 WA
//2022/08/25 08:12:08 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    long long N, A, B, ans;
    cin >> N >> A >> B;
    if ((B - A) % 2 == 0) {
        cout << (B - A) / 2 << endl;
        return 0;
    }
    // cout << min(N - A, B - 1) << endl;
    cout << min(A - 1, N - B) + 1 + (B - A) / 2 << endl;
    return 0;
}
// 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5
//   o       o
//     o   o  
//       o    
//     o             o
//   o             o
// o             o
// o           o
//   o       o
//     o   o
//       o
// (15) 3 10 -2-> 1 8 -1-> 1 7 -3-> 1 1; 