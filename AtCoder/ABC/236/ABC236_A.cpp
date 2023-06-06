// 2023/06/06 23:06:58
// 2023/06/06 23:09:29 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    string S;
    int a, b;
    cin >> S;
    cin >> a >> b;
    char tmp = S[a - 1];
    S[a - 1] = S[b - 1];
    S[b - 1] = tmp;
    cout << S << endl;
    return 0;
}