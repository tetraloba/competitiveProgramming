// 2024/03/20 19:19:13
// 2024/03/20 19:27:44 AC.
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<int> W(N);
    for (int &w : W) {
        cin >> w;
    }
    int num_c = 0, num_a = 0; // 子供と大人それぞれの数
    for (char c : S) {
        if (c == '1') {
            num_a++;
        } else {
            num_c++;
        }
    }
    map<int, int> mp;
    for (int i = 0; i < N; i++) {
        mp[W[i]] += S[i] == '1' ? -1 : 1;
    }
    int f = num_a, max_f = f;
    for (auto [k, v] : mp) {
        f += v;
        if (max_f < f) {
            max_f = f;
        }
    }
    cout << max_f << endl;
    return 0;
}
