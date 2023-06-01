//2022/08/16 11:09:11
//2022/08/16 11:12:18 AC.
#include <iostream>
using namespace std;
int main(){
    string S = "00110";
    int N = 1;
    cout << (S[S.size() - N - 1] - '0' ? "Yes" : "No") << endl;
    return 0;
}