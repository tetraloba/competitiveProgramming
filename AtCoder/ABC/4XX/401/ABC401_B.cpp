// 2025/04/12 21:01:03
// 
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    bool loggedin = false;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        if (S == "login") {
            loggedin = true;
        } else if (S == "logout") {
            loggedin = false;
        } else if (S == "private") {
            if (!loggedin) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
