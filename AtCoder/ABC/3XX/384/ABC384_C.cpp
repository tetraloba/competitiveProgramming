// 2025/01/02 10:26:39
// 2025/01/02 10:37:51 AC.
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
int main(){
    string names = "ABCDE";
    int scores[5];
    for (int &score : scores) {
        cin >> score;
    }

    map<int, set<string>> ans;
    int C_MAX = 1 << 5;
    for (int C = 0; C < C_MAX; C++) {
        int score = 0;
        string name = "";
        for (int i = 0; i < 5; i++) {
            if (C >> i & 1) {
                score += scores[i];
                name.push_back(names[i]);
            }
        }
        ans[score].insert(name);
    }

    auto itr = ans.rbegin();
    while (itr != ans.rend()) {
        auto [score, name_set] = *itr;
        for (string name : name_set) {
            cout << name << endl;
        }
        itr++;
    }
    return 0;
}
/*
組み合わせ全探索(bit全探索)してmapにでも追加すれば終いかな。(2025/01/02 10:29:24)
*/
