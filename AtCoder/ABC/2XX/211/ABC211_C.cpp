//2022/08/19 21:15:27
//2022/08/19 21:33:41 TLE シンプルな全探索。勿論撃沈。
#include <iostream>
#include <vector>
using namespace std;
long long stringSearch(char* S, char* T){
    if (T[0] == 0) {
        return 1;
    }
    long long ans = 0;
    for (int i = 0; S[i]; i++) {
        if (S[i] == T[0]) {
            ans+= stringSearch(&S[i + 1], &T[1]);
        }
    }
    return ans;
}
int main(){
    char S[100000], T[9] = "chokudai";
    cin >> S;
    cout << stringSearch(S, T) % 1000000007 << endl;
    return 0;
}