// 2026/07/12 13:46:39
// 2026/07/12 14:16:22 AC.
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
bool comp(const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.second < p2.second;
}
int main(){
    int N, K, M;
    cin >> N >> K >> M;
    vector<pair<int, int>> CV(N);
    for (int i = 0; i < N; i++) {
        cin >> CV[i].first >> CV[i].second;
    }

    sort(CV.rbegin(), CV.rend(), comp);
    set<int> selected_stone_indexes;
    set<int> selected_colors;
    long long ans = 0;
    for (auto itr = CV.begin(); itr != CV.end(); itr++) {
        // if (selected_stone_indexes.size() == K) {
        //     break;
        // }
        if (selected_colors.size() == M) {
            break;
        }
        if (selected_colors.find(itr->first) != selected_colors.end()) {
            // skip if the color already selected
            continue;
        }
        selected_stone_indexes.insert(itr - CV.begin());
        selected_colors.insert(itr->first);
        ans += itr->second;
    }
    for (auto itr = CV.begin(); itr != CV.end(); itr++) {
        if (selected_stone_indexes.size() == K) {
            break;
        }
        if (selected_stone_indexes.find(itr - CV.begin()) != selected_stone_indexes.end()) {
            // skip if the stone already selected
            continue;
        }
        selected_stone_indexes.insert(itr - CV.begin());
        ans += itr->second;
    }

    cout << ans << endl;
    return 0;
}
