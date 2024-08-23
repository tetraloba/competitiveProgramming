// 2024/08/24 07:46:20
// 2024/08/24 08:04:28 AC.
#include <iostream>
#include <vector>
#define MAX_S 1000000000
using namespace std;
int main(){
    int N, K, S;
    cin >> N >> K >> S;
    for (int i = 0; i < K; i++) {
        cout << S << ' ';
    }
    int notS = S == MAX_S ? MAX_S - 1 : MAX_S;
    for (int i = 0; i < N - K; i++) {
        cout << notS << ' ';
    }
    cout << endl;
    return 0;
}
/*
奇数の場合
5
5 5 5 5 5
2 3 2 3 2
んー？
K <= Nだよな？
SをK個並べるのはだめ？
*/
