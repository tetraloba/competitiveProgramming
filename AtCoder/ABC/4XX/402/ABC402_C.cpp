// 2025/05/09 15:35:02
// 2025/05/09 15:44:44 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> ingredient_to_dish(N);
    vector<int> cnt_bad_ingredient(M); // dish -> cnt
    for (int i = 0; i < M; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            a--;
            ingredient_to_dish[a].push_back(i);
            cnt_bad_ingredient[i]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int b;
        cin >> b;
        b--;
        for (int dish : ingredient_to_dish[b]) {
            cnt_bad_ingredient[dish]--;
            if (cnt_bad_ingredient[dish] == 0) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
/*
食材が料理を指して、料理が自分を指している食材の数を把握できればOKかな。(2025/05/09 15:36:58)
*/
