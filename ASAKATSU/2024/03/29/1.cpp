// 2024/03/29 07:30:09
// 2024/03/29 07:32:42 AC.
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<string> S(N);
    map<string, int> mp;
    for (string &s : S) {
        cin >> s;
        mp[s]++;
    }
    string ls[4] = {"AC", "WA", "TLE", "RE"};
    for (string l : ls) {
        cout << l << " x " << mp[l] << endl;
    }
    return 0;
}
