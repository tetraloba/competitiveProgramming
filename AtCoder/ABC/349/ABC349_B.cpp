// 2024/04/13 21:01:28
// 2024/04/13 21:06:26 AC.
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    string S;
    cin >> S;
    map<char, int> mp;
    for (char c : S) {
        mp[c]++;
    }
    map<int, int> mp2;
    for (auto [k, v] : mp) {
        mp2[v]++;
    }
    for (auto [k, v] : mp2) {
        if (v != 0 && v != 2) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
