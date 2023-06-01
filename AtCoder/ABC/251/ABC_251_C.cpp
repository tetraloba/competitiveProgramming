//2022-07-24 00:34:48
//2022-07-24 00:55:39 AC.
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main(){
    int N;
    cin >> N;
    int ans, max = -1;
    unordered_map<string, int> mp;
    for (int i = 0; i < N; i++) {
        string S;
        int T;
        cin >> S >> T;
        if (mp.find(S) == mp.end()) {
            if (max < (mp[S] = T)) {
                ans = i + 1;
                max = T;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}