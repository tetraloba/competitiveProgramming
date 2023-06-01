#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main(){
    int N;
    unordered_map<string, int> mp;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        if (mp[str]) {
            cout << str << '(' << mp[str] << ")\n"; 
        } else {
            cout << str << '\n';
        }
        mp[str]++;
    }
    return 0;
}